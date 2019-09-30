N = int(input())
l,r = [], []
for _ in range(N):
    a, b = map(int, input().split())
    l.append(a)
    r.append(b)

l.sort(reverse = True)
r.sort()

res = tmp = i = 0
while True:
    if l[i] > tmp:
        res += l[i] - tmp
        tmp = l[i]
    else:
        break
    if r[i] < tmp:
        res += tmp - r[i]
        tmp = r[i]
    else:
        break
    i += 1
res += abs(tmp)
res0 = res

res = tmp = i = 0
while True:
    if r[i] < tmp:
        res += tmp - r[i]
        tmp = r[i]
    else:
        break
    if l[i] > tmp:
        res += l[i] - tmp
        tmp = l[i]
    else:
        break
    i += 1
res += abs(tmp)

if res0 < res:
    print(res)
else:
    print(res0)