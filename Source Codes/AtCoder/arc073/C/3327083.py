N = int(input())
X = [0]*N
Y = [0]*N
for i in range(N):
    x, y = map(int, input().split())
    X[i], Y[i] = sorted([x, y])

ans = (max(X)-min(X)) * (max(Y)-min(Y))


L = []
for i, x in enumerate(X):
    L.append((x, i))
for i, y in enumerate(Y):
    L.append((y, i))
L.sort()

checker = [0]*N
cnt = 0
mi = float("inf")
j = 0
for xy, n in L:
    if checker[n] == 0:
        cnt += 1
        checker[n] = 1
    else:
        checker[n] = 2
    if cnt!=N:
        continue
    else:
        while True:
            xy2, n2 = L[j]
            if checker[n2] == 2:
                checker[n2] = 1
                j += 1
            else:
                break
        mi = min(mi, xy-xy2)

print(min(ans, mi*(max(Y)-min(X))))