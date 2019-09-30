# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())

n = N//9+1 if N % 9 != 0 else N//9
a = N % 9 if N % 9 != 0 else 9
print(str(a)*n)