# -*- coding: utf-8 -*-
N = int(input())
letter = input().split()

A = letter.count('Takahashikun')
B = letter.count('takahashikun')
C = letter.count('TAKAHASHIKUN')
D = letter.count('Takahashikun.')
E = letter.count('takahashikun.')
F = letter.count('TAKAHASHIKUN.')
G = letter.count('Takahashikun,')
H = letter.count('takahashikun,')
I = letter.count('TAKAHASHIKUN,')

print(A+B+C+D+E+F+G+H+I)