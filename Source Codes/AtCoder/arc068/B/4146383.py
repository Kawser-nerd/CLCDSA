from collections import Counter
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
Num = list(input().split())
C = Counter(Num)
ans = 0

l = [0]
v = len(C)
odd = len(list(filter(lambda x: x % 2 == 1, C.values())))
even = v - odd
ans += odd + even//2*2
print(ans)