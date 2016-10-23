
.data
_newline: .asciiz "\n"
.text
.globl main

main:
li $a0, 3
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 3
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
sgt $a0, $a0, $t1
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
sgt $a0, $a0, $t1
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
li $v0, 1
syscall

li $v0, 10
syscall
