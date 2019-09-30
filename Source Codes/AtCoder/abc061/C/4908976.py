N, K = map(int, input().split())
AB = list(list(map(int, input().split())) for _ in range(N))

AB.sort()
if AB[0][1] >= K:
    ans = AB[0][0]
else:
    for i in range(1,N):
        AB[i][1] += AB[i-1][1]
        if AB[i][1] >= K:
            ans = AB[i][0]
            break
print(ans)