N, Q = map(int, input().split())
lr = [[int(_) for _ in input().split()] for _ in range(Q)]
imos = [0]*(N+1)

for i in lr:
    imos[i[0]-1] += 1
    imos[i[1]]   -= 1

Cnum = [0]*(N+1)
tmp = 0
for i in range(N+1):
    tmp += imos[i]
    Cnum[i] = tmp

ans = ''
for i in Cnum:
    if i % 2 == 0:
        ans += '0'
    else:
        ans += '1'

print(ans[:-1])