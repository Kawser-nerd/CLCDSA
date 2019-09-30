import bisect
from math import factorial as fact
import sys
input = sys.stdin.readline
 
N = int(input())
prime = []
p_flag = [False] * (101)
p_flag[0] = p_flag[1] = True
 
for i in range(2, 101):
    if not p_flag[i]:
        prime.append(i)
        for j in range(2*i, 101, i):
            p_flag[j] = True
 
M = len(prime)
factor = [0]*M
 
for i in range(2, N+1):
    for j in range(M):
        tmp = prime[j]
        if tmp > i:
            break
        while i % tmp == 0:
            factor[j] += 1
            tmp *= prime[j]
 
factor = factor[::-1]
point74 = M - bisect.bisect_left(factor, 74)
point24 = M - bisect.bisect_left(factor, 24)
point14 = M - bisect.bisect_left(factor, 14)
point4 = M - bisect.bisect_left(factor, 4)
point2 = M - bisect.bisect_left(factor, 2)
 
if N < 10:
    ans = 0
else:
    ans = fact(point4)//(fact(point4-2)*fact(2)) * (point2-2)
    if point14 > 0:
        ans += point14 * (point4-1)
    if point24 > 0:
        ans += point24 * (point2-1)
    if point74 > 0:
        ans += point74
 
print(ans)