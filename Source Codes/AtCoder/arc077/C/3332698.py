n, m = map(int, input().split())
A = list(map(int, input().split()))

D0 = [0]*(2*m+10)
D1 = [0]*(2*m+10)
ans = 0

pa = A[0]-1
for a in A[1:]:
    a -= 1
    if a<pa:
        a += m
    ans += a-pa
    D1[pa+1] += 1
    D1[a] -= a-pa
    D1[a+1] += a-pa-1
    pa = a%m

for i, d1 in enumerate(D1):
    D0[i] = d1 + D0[i-1]

L = [0]*(2*m+10)

for i, d0 in enumerate(D0):
    L[i] = d0 + L[i-1]

for i, l in enumerate(L[m:]):
    L[i%m] += l

print(ans-max(L[:m]))