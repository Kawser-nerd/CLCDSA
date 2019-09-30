# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

A = list(map(int, input().split()))
B = list(map(int, input().split()))

print(sum(max(u, v) for u, v in zip(A, B)))