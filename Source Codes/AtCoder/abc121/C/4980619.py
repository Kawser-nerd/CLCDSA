N, M = map(int, input().split())
AB = [list(map(int, input().split())) for i in range(N)]
AB.sort(key = lambda x: x[0])

total = 0
i = 0

while True:
    total += AB[i][1]
    if total < M:
        i += 1
    else:
        break

ans = 0
for j in range(i):
    ans += AB[j][0]*AB[j][1]
ans += (M - sum(AB[p][1] for p in range(0,i))) * AB[i][0]
print(ans)