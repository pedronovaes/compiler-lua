
.data
_newline: .asciiz "\n"
.text
.globl main

main:
li $a0, 2
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 2
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
add $a0, $a0, $t1
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 3
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
add $a0, $a0, $t1
li $a0, 6
li $v0, 1
syscall
li $a0, 10
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 6
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
add $a0, $a0, $t1
li $a0, 16
li $v0, 1
syscall

li $v0, 10
syscall
