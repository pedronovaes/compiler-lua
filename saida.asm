
.data
b: .word 0
a: .word 0

_newline: .asciiz "\n"
.text
.globl main

main:
li $a0, 4
sw $a0, b
li $a0, 4
sw $a0, a
true_bw1:
lw $a0, b
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
li $t1, 0
beq $a0, $t1, false_bw1
li $a0, a
li $v0, 1
syscall
lw $a0, a
sw $a0, 0($sp)
addiu $sp, $sp, -4
li $a0, 1
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
addiu $sp, $sp, 4
lw $a0, 4($sp)
addiu $sp, $sp, 4
sub $a0, $a0, $t1
sw $a0, b
j true_bw1
false_bw1:

li $v0, 10
syscall
