# C
from heapq import heappush, heappop

N = int(input())
values = [0]*(2*N)

for i in range(N):
    A, B = map(int, input().split())
    values[i] = A
    values[i+N] = B

def argsort(R_arr):
    N = len(R_arr)
    R_args = [0]*N
    R_vars = [0]*N
    h = []
    for i in range(N):
        heappush(h, (R_arr[i], i))
    for i in range(N):
        a, b = heappop(h)
        R_args[i] = b
        R_vars[i] = a
    return R_vars, R_args

values_sorted, args = argsort(values)

# check for rare case
picked = [0]*N

for i in range(N):
    picked[args[i] % N] = 1
    
if sum(picked) == N:
    if args[N-1] % N == args[N] % N:
        res1 = sum(values_sorted[:(N-1)]) + values_sorted[N+1]
        res2 = sum(values_sorted[:(N+1)]) - values_sorted[N-2]
        res = min(res1, res2)
    else:
        res = sum(values_sorted[:(N-1)]) + values_sorted[N]
    res3 = sum(values[:N])
    res4 = sum(values[N:])
    res = min(res, res3, res4)
else:
    res = sum(values_sorted[:N])

print(res)