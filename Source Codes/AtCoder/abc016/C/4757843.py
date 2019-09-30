N, M = map(int, input().split())
table = [[0]*N for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    table[a-1][b-1] = 1
    table[b-1][a-1] = 1
ls = []
for i in range(N):
    a = set()
    for j, x in enumerate(table[i]):
        if x == 1:
            for k, y in enumerate(table[j]):
                if y == 1 and k != i and table[i][k] != 1:
                    a.add(k)
    ls.append(len(a))
print(*ls, sep='\n')