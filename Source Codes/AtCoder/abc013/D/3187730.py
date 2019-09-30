N, M, D = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

Amida = [[] for x in range(N + 1)]

for a in A:
    Amida[a  ].append((a + 1, len(Amida[a+1]) + 1))
    Amida[a+1].append((a    , len(Amida[a  ])    ))

rec = [0 for x in range(N)]
for i in range(1, N + 1):
    r = i
    j = 0
    while j < len(Amida[r]):
        r, j = Amida[r][j][0], Amida[r][j][1]
    rec[i-1] = r

kaijou = []
for i in reversed(range(30)):
    c = 2**i
    if c > D:
        continue
    kaijou.append(i)
    if D == c: break
    D -= c

R = []
R.append(rec)
for a in range(kaijou[0] + 1):
    R.append([R[-1][r-1] for r in R[-1]])

ans = [i for i in range(1, N + 1)]
for k in kaijou:
    ans = [R[k][i-1] for i in ans]
print(*ans, sep='\n')