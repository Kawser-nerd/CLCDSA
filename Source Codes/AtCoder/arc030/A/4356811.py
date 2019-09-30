# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
N = int(input())
K = int(input())
if N >= 2*K:
    print("YES")
else:
    print("NO")