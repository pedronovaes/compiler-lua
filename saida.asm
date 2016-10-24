
.data
a: .word 0
c: .word 0
d: .word 0

_newline: .asciiz "\n"
.text
.globl main

main:
li $a0, 1
sw $a0, a
li $a0, 2
sw $a0, c
li $a0, 3
sw $a0, d
lw $a0, a
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, c
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, d
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
add $a0, $a0, $t1
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
sgt $a0, $a0, $t1
li $t1, 0
beq $a0, $t1, false_bi1
lw $a0, c
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, d
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
add $a0, $a0, $t1
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
add $a0, $a0, $t1
li $v0, 1
syscall
j exit_if1
false_bi1:
li $a0, 24
li $v0, 1
syscall
exit_if1:

li $v0, 10
syscall
