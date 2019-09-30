N,K = map(int,input().split())
A = list(map(int,input().split()))

cums = [0]
cums_p = [0]
for a in A:
    cums.append(cums[-1] + a)
    cums_p.append(cums_p[-1] + max(0,a))

ans = -float('inf')
for l in range(N-K+1):
    free = cums_p[l] + cums_p[-1] - cums_p[l+K]
    cont = cums[l+K] - cums[l]
    ans = max(ans, free, free+cont)
print(ans)