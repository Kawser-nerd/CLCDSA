import bisect
N = int(input())
rs = [list(map(int, input().split())) for i in range(N)]
bs = [list(map(int, input().split())) for i in range(N)]
points = []
for r in rs:
    points.append((r[0], r[1], 'red'))
for b in bs:
    points.append((b[0], b[1], 'blue'))
points.sort()

rys = []
cnt = 0
for p in points:
    if p[2]=='red':
        bisect.insort_left(rys, p[1])
    else:
        idx = bisect.bisect_left(rys, p[1]) - 1
        if idx == -1:
            continue
        else:
            rys.pop(idx)
            cnt += 1
print(cnt)