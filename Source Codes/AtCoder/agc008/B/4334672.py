N,K = map(int,input().split())
A = list(map(int,input().split()))

cums = [0]
cump = [0]
for a in A:
    cums.append(cums[-1] + a)
    cump.append(cump[-1] + max(0,a))

ans = 0
for i in range(N-K+1):
    tmp = cump[i] + cump[-1] - cump[i+K]
    tmp += max(0, cums[i+K] - cums[i])
    ans = max(ans, tmp)
print(ans)