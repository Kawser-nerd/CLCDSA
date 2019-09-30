from math import factorial as fact
from operator import mul
from functools import reduce
import sys
input = sys.stdin.readline


def cmb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under


N, M = map(int, input().split())
num = []
p_flag = [True]*(int(M**0.5)+2)

for i in range(2, int(M**0.5)+2):
    if p_flag:
        for j in range(2*i, int(M**0.5)+2, i):
            p_flag[j] = False

        cnt = 0
        while M % i == 0:
            cnt += 1
            M //= i
        if cnt > 0:
            num.append(cnt)
        if M == 1:
            break
else:
    num.append(1)

ans = 1
for i in num:
    ans = (ans * cmb(N-1+i, i)) % (10**9+7)
print(ans)