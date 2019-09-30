L,N = map(int,input().split())
X = [int(input()) for i in range(N)]

if N == 1:
    print(max(X[0],L-X[0]))
    exit()

cum_l = [0]
for x in X:
    cum_l.append(cum_l[-1] + x)

cum_r = [0]
for x in reversed(X):
    cum_r.append(cum_r[-1] + L-x)

ans = 0
for st_l in range(1,N+1):
    m = N - st_l
    r = m - m//2
    l = st_l + m//2
    tmp = (cum_l[l] - cum_l[st_l-1] + cum_r[r]) * 2
    if m%2:
        tmp -= (L - X[-r])
    else:
        tmp -= X[l-1]
    ans = max(ans, tmp)

for st_r in range(1,N+1):
    m = N - st_r
    l = m - m//2
    r = st_r + m//2
    tmp = (cum_r[r] - cum_r[st_r-1] + cum_l[l]) * 2
    if m%2:
        tmp -= X[l-1]
    else:
        tmp -= (L - X[-r])
    ans = max(ans, tmp)

print(ans)