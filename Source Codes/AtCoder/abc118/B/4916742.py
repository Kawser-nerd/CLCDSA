n, m = map(int, input().split())
ka = [list(map(int, input().split())) for i in range(n)]
l = [0] * m

for i in range(n):
    for j in ka[i][1:]:
        l[j - 1] += 1

print(l.count(n))