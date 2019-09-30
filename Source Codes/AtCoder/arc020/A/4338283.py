# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

A, B = map(lambda x: abs(int(x)), input().split())
if A == B:
    print("Draw")
elif A > B:
    print("Bug")
else:
    print("Ant")