#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

#define C_ARITHMETIC 0
#define C_PUSH 1
#define C_LABEL 2
#define C_GOTO 3
#define C_POP 4
#define C_IF 5
#define C_FUNCTION 6
#define C_RETURN 7
#define C_CALL 8
#define INVALID 9
using namespace std;

string trim(string input)
{
    int l = 0;
    int r = input.size() - 1;
    while (input[l] == ' ' || input[l] == '\r' || input[l] == '/')
    {
        l++;
    }

    while (input[r] == ' ' || input[r] == '\r' || input[r] == '/')
    {
        r--;
    }

    int length = r - l + 1;

    return input.substr(l, length);
}

string removeComment(string input)
{
    string output = input;
    while (output.find("//") != -1)
    {
        output = output.substr(0, output.size() - 1);
    }

    return output;
}

//Ensure that labels are unique for each function
//Each static variable should be namedspaced  by the file it is in
//Each function, when called, should  have  access to the static variables of the file it is present in
class CodeWriter
{
    ofstream outstream;
    int labelCount = 0;
    string currentFunctionName = "";
    string currentFileName = "";

  public:
    CodeWriter(char *path)
    {
        outstream.open(path);
    }

    void setCurrentFileName(string name)
    {
        currentFileName = name;
    }

    void writeCommandSequence(vector<string> commandSequence)
    {
        for (int i = 0; i < commandSequence.size(); i++)
        {
            writeLine(commandSequence[i]);
        }
    }
    void writePushCommand()
    {
        /*
        @SP
        A=M
        A=A+1
        M=D
        */
        vector<string> commandSequence{
            "@SP",
            "A=M",
            "M=D",
            "@SP",
            "M=M+1"};

        writeCommandSequence(commandSequence);
    }

    void writeLabel(string label)
    {
        writeLine("(" + currentFunctionName + "$" + label + ")");
    }

    void writeGoto(string label)
    {
        writeLine("@" + currentFunctionName + "$" + label);
        writeLine("0; JMP");
    }

    void writeIf(string label)
    {
        writePopCommand();
        writeLine("@" + currentFunctionName + "$" + label);
        writeLine("D=D+1");
        writeLine("D; JEQ");

        //check
    }

    void writeFunction(string functionName, string numlocals)
    {
        int numberOfLocals = stoi(numlocals);
        for (int i = 0; i < numberOfLocals; i++)
        {
            writePushPop(C_PUSH, "constant", 0);
            writePushPop(C_POP, "local", to_string(i));
        }
    }

    void writePopCommand()
    {
        /*
        @SP 
        A=M
        D=M
        A=A-1
        */

        vector<string> commandSequence{
            "@SP",
            "M=M-1",
            "A=M",
            "D=M",
        };

        writeCommandSequence(commandSequence);
    }

    string returnOperand(string input)
    {
        if (input == "add")
        {
            return "+";
        }

        if (input == "sub")
        {
            return "-";
        }

        if (input == "or")
        {
            return "|";
        }

        if (input == "and")
        {
            return "&";
        }

        if (input == "eq")
        {
            return "JEQ";
        }

        if (input == "lt")
        {
            return "JLT";
        }

        if (input == "gt")
        {
            return "JGT";
        }

        return "INVALID";
    }
    void writeArithmetic(string command)
    {
        if (command == "neg" || command == "not")
        {
            writePopCommand();
            if (command == "not")
            {
                writeLine("D=!D");
            }

            else
            {
                writeLine("A=0");
                writeLine("A=A-D");
                writeLine("D=A");
            }

            writePushCommand();
        }

        else
        {
            string operand = "";
            operand = returnOperand(command);
            if (command == "add" || command == "sub" || command == "or" || command == "and")
            {

                writePopCommand();
                writeLine("@R13");
                writeLine("M=D");
                writePopCommand();
                writeLine("@R13");
                writeLine("D=D" + operand + "M");
                writePushCommand();
            }

            else
            {
                writePopCommand();
                writeLine("@R13");
                writeLine("M=D");
                writePopCommand();
                writeLine("@R13");
                writeLine("D=D-M");
                writeLine("@TRUE" + to_string(labelCount));
                writeLine("D;" + operand);
                writeLine("D=0");
                writePushCommand();
                writeLine("@END" + to_string(labelCount));
                writeLine("0; JMP");
                writeLine("(TRUE" + to_string(labelCount) + ")");
                writeLine("D=-1");
                writePushCommand();
                writeLine("(END" + to_string(labelCount) + ")");

                labelCount++;
            }
        }

        /*pop command
        D now has the operand
        @R13
        M=D
        pop command again
        D now has the operand
        @R13
        D=DopM
        push command
        */
    }
    //Have function for assigning values to D

    string getBaseName(string segment)
    {
        if (segment == "local")
        {
            return "LCL";
        }

        if (segment == "argument")
        {
            return "ARG";
        }

        if (segment == "this")
        {
            return "THIS";
        }

        if (segment == "that")
        {
            return "THAT";
        }
    }
    void writePushPop(int commandType, string segment, string index)
    {

        if (segment == "constant")
        {
            writeLine("@" + index);
            writeLine("D=A");
        }

        else if (segment == "local" || segment == "argument" || segment == "this" || segment == "that")
        {
            writeLine("@" + getBaseName(segment));
            writeLine("D=M");
            writeLine("@" + index);
            writeLine("D=D+A");
            writeLine("A=D");
            // writeLine("A=M");
        }

        else if (segment == "pointer" || segment == "temp")
        {
            string k = segment == "pointer" ? "3" : "5";
            writeLine("@" + k);
            writeLine("D=A");
            writeLine("@" + index);
            writeLine("D=D+A");
            writeLine("A=D");
        }

        else if(segment=="static"){
            writeLine("@"+currentFileName+"."+index);
        }

        if (commandType == C_PUSH)
        {

            if (segment != "constant")
            {
                writeLine("D=M");
            }

            writePushCommand();
        }

        else
        {

            if (segment != "constant")
            {
                writeLine("D=A");
                writeLine("@R13");
                writeLine("M=D");
                writePopCommand();
                writeLine("@R13");
                writeLine("A=M");
                writeLine("M=D");
            }
        }
    }
    void writeLine(string line)
    {
        outstream << line;
        outstream << "\n";
    }
};
class Parser
{
    string currentCommand;
    int currentCommandType;
    int firstFree;
    ifstream instream;

  public:
    Parser(const char *path)
    {
        instream.open(path);
        firstFree = 16;
    }

    bool hasMoreCommands()
    {
        return !instream.eof();
    }

    void advance()
    {
        getline(instream, currentCommand);
        currentCommand = removeComment(currentCommand);
        currentCommand = trim(currentCommand);
        cout << "C" << currentCommand << endl;
    }

    int commandType()
    {

        //
        currentCommandType = INVALID;

        if (currentCommand.find("push") != -1)
        {
            currentCommandType = C_PUSH;
        }

        else if (currentCommand.find("pop") != -1)
        {
            currentCommandType = C_POP;
        }

        else if (currentCommand.find("label") == 0)
        {
            currentCommandType = C_LABEL;
        }

        else if (currentCommand.find("function") == 0)
        {
            currentCommandType = C_FUNCTION;
        }

        else if (currentCommand.find("return") == 0)
        {
            currentCommandType = C_RETURN;
        }

        else if (currentCommand.find("goto") == 0)
        {
            currentCommandType = C_GOTO;
        }

        else if (currentCommand.find("call") == 0)
        {
            currentCommandType = C_CALL;
        }

        else if (currentCommand.find("if") == 0)
        {
            currentCommandType = C_IF;
        }

        else
        {
            string arithmeticCommands[] = {"add", "sub", "neg", "eq", "gt", "lt", "and", "or", "not"};
            for (int i = 0; i < 9; i++)
            {
                if (currentCommand.find(arithmeticCommands[i]) != -1)
                {
                    currentCommandType = C_ARITHMETIC;
                    break;
                }
            }
        }

        return currentCommandType;
    }

    vector<string> tokenize(string input, char delim)
    {
        vector<string> output;
        int k = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == delim)
            {
                string token = input.substr(k, i - k);
                if (token.find(delim) == -1)
                {
                    output.push_back(token);
                }
                k = i + 1;
            }
        }

        if (k < input.size())
        {
            output.push_back(input.substr(k));
        }

        return output;
    }

    string arg1()
    {
        if (currentCommandType != INVALID && currentCommandType != C_RETURN)
        {
            if (currentCommandType == C_ARITHMETIC)
            {
                return currentCommand;
            }

            else
            {
                vector<string> tokens = tokenize(currentCommand, ' ');
                return tokens[1];
            }
        }

        return "INVALID";
    }

    string arg2()
    {
        if (currentCommandType == C_PUSH || currentCommandType == C_POP || currentCommandType == C_FUNCTION || currentCommandType == C_CALL)
        {
            vector<string> tokens = tokenize(currentCommand, ' ');
            return tokens[2];
        }

        return "INVALID";
    }
};

int main(int argc, char *argv[])

{
    //Interpret as colleciton
    //Each time you start traversing a file, inform codewriter class
    char *inputPath = argv[1];
    char *outputPath = argv[2];

    int inputPathLength = strlen(inputPath);
    string extension = fs::path(inputPath).extension();
    CodeWriter writer(outputPath);
    vector<string> files;

    if (extension != ".vm")
    {
        for (auto &i : fs::directory_iterator(inputPath))
        {
            string path = i.path();
            if (i.path().extension() == ".vm")
            {
                files.push_back(path);
            }
        }
    }

    else
    {
        files.push_back(inputPath);
    }

    for (int i = 0; i < files.size(); i++)
    {
        const char* filepath = files[i].c_str();
        string filename = fs::path(filepath).filename();
        Parser parser(filepath);
        writer.setCurrentFileName(filename);
        while (parser.hasMoreCommands())
        {
            parser.advance();
            cout << parser.commandType() << endl;
            cout << parser.arg1() << endl;
            cout << parser.arg2() << endl;
            cout << endl;
            //CAN LABESL BE A PROBLEM
            if (parser.commandType() == C_ARITHMETIC)
            {
                string command = parser.arg1();
                writer.writeArithmetic(command);
            }

            if (parser.commandType() == C_PUSH || parser.commandType() == C_POP)
            {
                string segment = parser.arg1();
                string index = parser.arg2();
                writer.writePushPop(parser.commandType(), segment, index);
            }
        }
    }
}