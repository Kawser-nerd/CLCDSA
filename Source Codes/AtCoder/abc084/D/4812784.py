import math
from itertools import accumulate


def is_prime(n):
    if n == 1:
        return 0

    for k in range(2, int(math.sqrt(n)) + 1):
        if n % k == 0:
            return 0

    return 1


Q = int(input())
L = [0]*Q
R = [0]*Q

for i in range(Q):
    L[i], R[i] = list(map(int, input().split()))

min_L = min(L)
max_R = max(R)

check = []
for i in range(min_L, max_R+1):
    if (i % 2 == 1):
        flg = (is_prime(i) and is_prime((i+1)/2))
    else:
        flg = 0
    check.append(flg)

# ???
check = [0] + check
check = list(accumulate(check))

for i in range(Q):
    print(check[R[i] - min_L + 1] - check[L[i] - min_L])