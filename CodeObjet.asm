TITLE ProgName

PILE SEGMENT STACK
	DB 100 DUP (?)
PILE ENDS

DATA SEGMENT
	T0 DW 0
	T1 DW 0
	T2 DW 0
	T3 DW 0
	T4 DW 0
	T5 DW 0
	T6 DW 0
	T7 DW 0
	T8 DW 0
	T9 DW 0
	T10 DW 0
	T11 DW 0
	T12 DW 0
	T13 DW 0
	T14 DW 0
	T15 DW 0
	T16 DW 0
DATA ENDS

CODE SEGMENT
MAIN:
	ASSUME CS:CODE, DS:DATA, SS:PILE
	MOV AX, DATA
	MOV DS, AX
		MOV AX, p2
		MOV p1, AX
		MOV AX, 4
		MUL AX, p2
		PUSH AX
		POP AX
		MOV p3, AX
		MOV AX, 4
		ADD AX, 1
		PUSH AX
		POP AX
		MOV e1, AX
		MOV AX, 4
		MUL AX, e1
		PUSH AX
		POP AX
		MOV e3, AX
		MOV AX, a
		ADD AX, b
		PUSH AX
		POP AX
		MOV t1, AX
		MOV AX, c
		MUL AX, t1
		PUSH AX
		POP AX
		MOV t2, AX
		MOV AX, a
		ADD AX, b
		PUSH AX
		POP AX
		MOV t3, AX
		MOV AX, t3
		MUL AX, e
		PUSH AX
		POP AX
		MOV t4, AX
		MOV AX, u
		MUL AX, 2
		PUSH AX
		POP AX
		MOV mult, AX
		MOV AX, a
		SUB AX, a
		PUSH AX
		POP AX
		MOV b, AX
		MOV AX, b
		SUB AX, 4
		PUSH AX
		POP AX
		MOV x, AX
		MOV AX, 0
		ADD AX, j
		PUSH AX
		POP AX
		MOV i, AX
		MOV AX, i
		ADD AX, 2
		PUSH AX
		POP AX
		MOV k, AX
		MOV AX, var
		ADD AX, 1
		PUSH AX
		POP AX
		MOV add, AX
		MOV AX, add
		SUB AX, 1
		PUSH AX
		POP AX
		MOV sub, AX
		MOV AX, y
		MUL AX, 1
		PUSH AX
		POP AX
		MOV x, AX
		MOV AX, y
		CWD
		DIV 1
		PUSH AX
		POP AX
		MOV x, AX
		MOV AX, 0
		MOV unused1, AX
		MOV AX, unused1
		ADD AX, 456
		PUSH AX
		POP AX
		MOV unused2, AX
		MOV AX, 42
		MOV shown, AX
	MOV AX, 4C00h
	INT 21h
CODE ENDS
END MAIN
