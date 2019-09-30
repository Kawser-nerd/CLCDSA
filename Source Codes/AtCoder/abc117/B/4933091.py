#!/usr/bin/env python3

N = int(input())
L = input().split()
L_num = []

for i in range(len(L)):
    L_num.append(int(L[i]))

L_num.sort()

total = 0
for j in range(len(L) - 1):
    total += L_num[j]

if total <= L_num[N-1]:
    print("No")
else:
    print("Yes")