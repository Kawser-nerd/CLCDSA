from itertools import accumulate
N,Q = map(int,input().split())
b = [ 0 for _ in range(N)]
for _ in range(Q):
    l,r = map(int,input().split())
    b[l-1] += 1
    if r < N:
        b[r] -= 1
b = list(accumulate(b))  
for i in range(N):
    b[i] = str(b[i] % 2)
print("".join(b))