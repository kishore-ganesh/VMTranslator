@SP
A=M
D=M
A=A-1
@R13
M=D
@SP
A=M
D=M
A=A-1
@R13
D+M
@SP
A=M
A=A+1
M=D
@SP
A=M
D=M
A=A-1
A=0
A=A-D
D=A
@SP
A=M
A=A+1
M=D
@SP
A=M
D=M
A=A-1
@R13
M=D
@SP
A=M
D=M
A=A-1
@R13
D-M
@SP
A=M
A=A+1
M=D
@SP
A=M
D=M
A=A-1
@R13
M=D
@SP
A=M
D=M
A=A-1
D=D-M
@TRUE
D;JEQ
D=0
@SP
A=M
A=A+1
M=D
(END)
@END
0; JMP
(TRUE)
D=-1
@SP
A=M
A=A+1
M=D
@SP
A=M
D=M
A=A-1
@R13
M=D
@SP
A=M
D=M
A=A-1
D=D-M
@TRUE
D;JLT
D=0
@SP
A=M
A=A+1
M=D
(END)
@END
0; JMP
(TRUE)
D=-1
@SP
A=M
A=A+1
M=D
@SP
A=M
D=M
A=A-1
@R13
M=D
@SP
A=M
D=M
A=A-1
D=D-M
@TRUE
D;JGT
D=0
@SP
A=M
A=A+1
M=D
(END)
@END
0; JMP
(TRUE)
D=-1
@SP
A=M
A=A+1
M=D
@SP
A=M
D=M
A=A-1
@R13
M=D
@SP
A=M
D=M
A=A-1
@R13
D&M
@SP
A=M
A=A+1
M=D
@SP
A=M
D=M
A=A-1
@R13
M=D
@SP
A=M
D=M
A=A-1
@R13
D|M
@SP
A=M
A=A+1
M=D
@SP
A=M
D=M
A=A-1
D=!D
@SP
A=M
A=A+1
M=D