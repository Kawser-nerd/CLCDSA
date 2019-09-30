import math
from itertools import accumulate

def is_prime(n):
    if n == 1: return 0

    for k in range(2, int(math.sqrt(n)) + 1):
        if n % k == 0:
            return 0
    return 1

Q = int(input())
L = [0]*Q
R = [0]*Q

for j in range(Q):
    L[j],R[j] = [int(i) for i in input().split()]

min_L = min(L)
max_R = max(R)

li = []
for i in range(min_L,max_R+1,1):
    if i%2 == 1:
        li.append(is_prime(i) * is_prime((i+1)//2))
    else:
        li.append(0)

ans = [0]
ans += list(accumulate(li))


for i,j in zip(L,R):
    print(ans[j-min_L+1] - ans[i-min_L])