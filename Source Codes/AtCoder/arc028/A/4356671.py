# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, A, B = map(int, input().split())

s = A+B

if N % s > A or N % s == 0:
    print("Bug")
else:
    print("Ant")