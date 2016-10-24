
.data
_newline: .asciiz "\n"
.text
.globl main

main:
li $a0, 1
li $a0, 1
li $v0, 1
syscall
li $a0, 123
li $a0, 123
li $v0, 1
syscall
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 123
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
add $a0, $a0, $t1
li $a0, 124
li $v0, 1
syscall

li $v0, 10
syscall
