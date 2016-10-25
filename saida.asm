
.data
i: .word 0

_newline: .asciiz "\n"
.text
.globl main

main:
li $a0, 0
sw $a0, i
li $a0, 0
sw $a0, i
li $a0, 10
move $t0, $a0
true_bf1:
lw $a0, i
bgt $a0, $t0, false_bf1
lw $a0, i
li $v0, 1
syscall
li $v0, 4
la $a0, _newline
syscall
lw $a0, i
li $t1, 1
add $a0, $a0, $t1
sw $a0, i
j true_bf1
false_bf1:
li $v0, 4
la $a0, _newline
syscall

li $v0, 10
syscall
