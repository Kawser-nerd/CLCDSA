# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
N, M = map(int, input().split())
if M >= 2:
    print(1)
else:
    print(2)