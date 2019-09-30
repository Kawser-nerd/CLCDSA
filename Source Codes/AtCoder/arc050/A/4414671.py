# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

C, c = input().split()
if ord(C)-ord('A') == ord(c)-ord('a'):
    print("Yes")
else:
    print("No")