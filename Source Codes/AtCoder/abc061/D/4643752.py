N, M = [int(i) for i in input().split()]
G_ls = []
d = [-float("inf") for i in range(N)]
for i in range(M):
    a, b, c = [int(i) for i in input().split()]
    a -= 1
    b -= 1
    G_ls.append([a,b,c])

def update(x, y, is_updated):
    if x < y:
        is_updated = True
        x = y
    return x, is_updated
d[0] = 0
G_ls.sort(key=lambda x:x[0])
for i in range(N):
    for j in range(M):
        is_updated = False
        a, b, c = G_ls[j]
        d[b], is_updated = update(d[b], d[a] + c, is_updated)
if is_updated:
    print("inf")
else:
    print(d[-1])