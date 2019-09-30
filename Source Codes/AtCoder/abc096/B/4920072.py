#coding: utf-8
l = list(map(int, input().split()))
K = int(input())
l.sort()
print(sum(l[:2]) + l[-1] * 2 ** K)