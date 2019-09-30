N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]

suma = sumb = 0
elems = []
for i,(a,b) in enumerate(src):
    suma += a
    sumb += b
    elems.append((a,i))
    elems.append((b,i))
ans = min(suma, sumb)
elems.sort()

sumw = 0
used = [0]*N
dup = False
for w,i in elems[:N]:
    sumw += w
    used[i] += 1
    if used[i] > 1: dup = True

if dup:
    ans = min(ans, sumw)
    print(ans)
    exit()

for i,(a,b) in enumerate(src):
    if a > b:
        a,b = b,a
    neww = elems[N][0] if i != elems[N][1] else elems[N+1][0]
    tmp = sumw - a + neww
    ans = min(ans, tmp)
print(ans)