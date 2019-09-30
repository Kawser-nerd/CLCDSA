import itertools

n,m = map(int, input().split())

line = [[0 for i in range(n)] for j in range(n)]

for i in range(m):
    a,b = map(int, input().split())
    line[a-1][b-1] = 1
    line[b-1][a-1] = 1

ans = 0

p = [i for i in range(1, n)]

for x in itertools.permutations(p):
    x = list(x)
    x.insert(0,0)
    for i in range(n-1):
        if not line[x[i]][x[i+1]]:
            break
        if i == n-2:
            ans += 1

print(ans)