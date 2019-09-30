# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

_ = int(input())
A = list(map(int, input().split()))
A = sorted(A, reverse=True)
print(sum(A[0::2]))