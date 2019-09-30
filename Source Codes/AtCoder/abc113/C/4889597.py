n, m = map(int, input().split())
PY = [tuple(map(int, input().split())) for _ in range(m)]
sPY = sorted(PY, key=lambda x:(x[0], x[1]))

ans = {}
key, cnt = 1, 1
for p, y in sPY:
    if p != key:
        key = p
        cnt = 1
    ans[y] = cnt
    cnt += 1

for p, y in PY:
    a = str(p).zfill(6)
    b = str(ans[y]).zfill(6)
    print("{}{}".format(a, b))