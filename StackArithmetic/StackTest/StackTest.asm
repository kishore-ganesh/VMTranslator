@17
D=A
@SP
A=M
M=D
@SP
M=M+1
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D-M
@TRUE0
D;JEQ
D=0
@SP
A=M
M=D
@SP
M=M+1
@END0
0; JMP
(TRUE0)
D=-1
@SP
A=M
M=D
@SP
M=M+1
(END0)
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D-M
@TRUE1
D;JEQ
D=0
@SP
A=M
M=D
@SP
M=M+1
@END1
0; JMP
(TRUE1)
D=-1
@SP
A=M
M=D
@SP
M=M+1
(END1)
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D-M
@TRUE2
D;JEQ
D=0
@SP
A=M
M=D
@SP
M=M+1
@END2
0; JMP
(TRUE2)
D=-1
@SP
A=M
M=D
@SP
M=M+1
(END2)
@892
D=A
@SP
A=M
M=D
@SP
M=M+1
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D-M
@TRUE3
D;JLT
D=0
@SP
A=M
M=D
@SP
M=M+1
@END3
0; JMP
(TRUE3)
D=-1
@SP
A=M
M=D
@SP
M=M+1
(END3)
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
@892
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D-M
@TRUE4
D;JLT
D=0
@SP
A=M
M=D
@SP
M=M+1
@END4
0; JMP
(TRUE4)
D=-1
@SP
A=M
M=D
@SP
M=M+1
(END4)
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D-M
@TRUE5
D;JLT
D=0
@SP
A=M
M=D
@SP
M=M+1
@END5
0; JMP
(TRUE5)
D=-1
@SP
A=M
M=D
@SP
M=M+1
(END5)
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D-M
@TRUE6
D;JGT
D=0
@SP
A=M
M=D
@SP
M=M+1
@END6
0; JMP
(TRUE6)
D=-1
@SP
A=M
M=D
@SP
M=M+1
(END6)
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D-M
@TRUE7
D;JGT
D=0
@SP
A=M
M=D
@SP
M=M+1
@END7
0; JMP
(TRUE7)
D=-1
@SP
A=M
M=D
@SP
M=M+1
(END7)
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D-M
@TRUE8
D;JGT
D=0
@SP
A=M
M=D
@SP
M=M+1
@END8
0; JMP
(TRUE8)
D=-1
@SP
A=M
M=D
@SP
M=M+1
(END8)
@57
D=A
@SP
A=M
M=D
@SP
M=M+1
@31
D=A
@SP
A=M
M=D
@SP
M=M+1
@53
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D+M
@SP
A=M
M=D
@SP
M=M+1
@112
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D-M
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
A=0
A=A-D
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D&M
@SP
A=M
M=D
@SP
M=M+1
@82
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
D=D|M
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
D=!D
@SP
A=M
M=D
@SP
M=M+1
