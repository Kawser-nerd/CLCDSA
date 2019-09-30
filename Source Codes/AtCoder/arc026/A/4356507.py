# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, A, B = map(int, input().split())
print(max(0, (N-5))*A+B*min(5, N))