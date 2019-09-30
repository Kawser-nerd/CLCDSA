N, Q = map(int, input().split())
a = [0] * N

for i in range(Q):
    l, r, t = map(int, input().split())
    for j in range(l,r+1):
        a[j-1] = t

for i in range(N):
    print(a[i])