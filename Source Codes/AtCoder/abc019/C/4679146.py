# coding: utf-8
N = int(input())
A = list(map(int, input().split()))
s = set()
for a in A:
    while a % 2 == 0:
        a //= 2
    s.add(a)
print(len(s))