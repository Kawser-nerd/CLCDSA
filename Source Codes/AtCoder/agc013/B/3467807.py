def dfs():
    ans = []
    vNow = 0
    while True:
        useds[vNow] = True
        ans.append(vNow + 1)
        for v2 in adjL[vNow]:
            if not useds[v2]:
                vNow = v2
                break
        else:
            break

    return ans


N, M = map(int, input().split())
adjL = [[] for v in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    adjL[a - 1].append(b - 1)
    adjL[b - 1].append(a - 1)

useds = [False] * N
ans1 = dfs()
ans2 = dfs()
print(len(ans1) + len(ans2) - 1)
print(' '.join(map(str, ans1[::-1] + ans2[1:])))