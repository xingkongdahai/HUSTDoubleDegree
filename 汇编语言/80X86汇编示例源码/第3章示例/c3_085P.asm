; C3_085P 显示字符串
;C3_085J1 强调显示的数据在DS:DX中
;C3_085J2 强调以'$'结尾


STACK SEGMENT STACK
      DB 200 DUP(0)
STACK ENDS

DATA  SEGMENT
BUF   DB  0DH,0AH,'I WISH YOU SUCCESS! $'
DATA  ENDS   

CODE SEGMENT
     ASSUME CS:CODE,DS:DATA,SS:STACK

START:MOV AX,DATA
      MOV DS,AX

      LEA DX,BUF
      MOV AH,9
      INT 21H
      MOV AH,4CH
      INT 21H
CODE  ENDS
      END START

