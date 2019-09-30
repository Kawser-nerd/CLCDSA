N, M, D = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

rec = list(range(1, N + 1))
for a in reversed(A):
    rec[a-1], rec[a] = rec[a], rec[a-1]

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

ans = list(range(1, N + 1))
for k in kaijou:
    ans = [R[k][i-1] for i in ans]
print(*ans, sep='\n')