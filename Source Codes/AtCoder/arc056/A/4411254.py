# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

A, B, K, L = map(int, input().split())

s = K//L
print(min(K*A, s*B+(K-s*L)*A, (s+1)*B))