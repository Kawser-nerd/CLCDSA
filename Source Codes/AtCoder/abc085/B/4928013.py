#coding: utf-8
N = int(input())
l = []
for i in range(N):
    l.append(int(input()))
l.sort()
l = list(set(l))
print(len(l))