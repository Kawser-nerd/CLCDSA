N,M = map(int, input().split())
ab = []
for m in range(M):
    a,b = map(int, input().split())
    ab.append((a,b))

ab = sorted(ab, key=lambda x: x[1])

cnt = 0
last = -1
for a, b in ab:
    if a < last:
        continue
    else:
        cnt += 1
        last = b

print(cnt)