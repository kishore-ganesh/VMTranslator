# VMTranslator
A translator that translates VM intermediate code for the Jack Machine into Assembly Code

It implements the interface described in the book Nand2Tetris. At the heart of the VM language is a stack based virtual machine that uses push and pop operations to perform all operations. 

NOTE: The provided test programs are from Nand2Tetris. All credits go to the book authors. It is included only for testing purposes.

The stack provides a very elegant approach for calling functions, in which the current state of the function, as well as the return address is pushed onto the stack. Before calling a function, you push its arguments onto the stack. ANd once a function's execution is complete, all of the local variables of the function are destroyed, and the program pointer goes back to the return address pushed into the stack.

Current State: Passes all tests, but needs to be optimized to fit the 32K memory of the Hack Computer.
