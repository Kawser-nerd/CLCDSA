# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

H, B = map(float, input().split())
print(B*H*H/10**4)