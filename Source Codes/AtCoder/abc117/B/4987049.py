# coding: utf-8

N = int(input())
L = list(map(int, input().split()))
total = sum(L)

if total - max(L) > max(L):
    print("Yes")
else:
    print("No")