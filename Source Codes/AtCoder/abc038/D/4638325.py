from bisect import bisect_left

n = int(input())
wh = []
for _ in range(n):
    w, h = map(int, input().split())
    wh.append([w, -h])

wh.sort()

bit = [ -wh[0][1] ]

for i in range(1, n):
    h = -wh[i][1]
    if bit[-1] < h:
        bit.append(h)
    else:
        bit[bisect_left(bit, h)] = h

print(len(bit))