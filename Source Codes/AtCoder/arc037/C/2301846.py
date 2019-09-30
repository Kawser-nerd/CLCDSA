# -*- coding: utf-8 -*-
from bisect import bisect
def inpl(): return map(int, input().split())
N, K = inpl()
A = sorted(inpl())
B = sorted(inpl())

ok = 10**18
ng = 0

def judge(A, B, m, K):
    tmp = 0
    for b in B:
        tmp += bisect(A, m//b)
    if tmp < K:
        return False
    else:
        return True

while ok-ng > 1:
    m = (ok+ng)//2
    if judge(A, B, m, K):
        ok = m
    else:
        ng = m

print(ok)