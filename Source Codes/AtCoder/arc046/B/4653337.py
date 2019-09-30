# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
A, B = map(int, input().split())
vic = True

if N <= A:
    vic = True
elif N > A:
    if A == B:
        if N % (A+1) == 0:
            vic = False
    else:
        if A < B:
            vic = False

if vic:
    print("Takahashi")
else:
    print("Aoki")