N,M = (int(x) for x in input().split())
group = [[i+1] for i in range(N)]
for i in range(M):
    x,y = (int(p) for p in input().split())
    group[x-1].append(y)
    group[y-1].append(x)
ans = 1

for i in range(2**N):
    cli = []
    for j in range(N):
        if int(i/(2**j)) % 2 != 0:
            cli.append(j+1)
    if len(cli) > ans:
        if (all((k in group[cli[j]-1] for j in range(len(cli)) for k in cli))):
            ans = len(cli)

print(ans)