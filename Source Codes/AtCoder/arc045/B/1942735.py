N,M = map(int,input().split())
src = []
imos = [0] * (N+1)
for i in range(M):
    s,t = map(int,input().split())
    src.append((s,t))
    imos[s-1] += 1
    imos[t] -= 1

cum = 0
must = [0]
for i in range(N+1):
    cum += imos[i]
    must.append(must[-1] + (1 if cum == 1 else 0))

ans = []
for i in range(M):
    s,t = src[i]
    if must[s-1] == must[t]:
        ans.append(i+1)
print(len(ans))
for a in ans:
    print(a)