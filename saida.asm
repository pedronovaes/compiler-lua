[programa [bloco [comando [T_WHILE while][opbin [T_NAME a][T_EQ ==][T_NUMBER 0]][T_DO do][bloco [comando [chamadadefuncao [T_NAME print][T_OPENPAR (][listaexp [listaexp [T_NUMBER 1]]][T_CLOSEPAR )]]][comando [comando [listadenomes [T_NAME a]][T_ASSIGN =][listaexp [T_NUMBER 1]]]]][T_END end]]]]
.data
_newline: .asciiz "\n"
.text
.globl main

main:

li $v0, 10
syscall
