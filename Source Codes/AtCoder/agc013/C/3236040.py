import sys

N, L, T = map(int, input().split())
a = [list(map(int, l.split())) for l in sys.stdin]
_a = sorted((x+T*(1 if w == 1 else -1))%L for x, w in a)
num = 0
start, direction = a[0]
eps = 1e-9

for i, (x, w) in enumerate(a):
    if w == direction:
        continue
    if direction == 1:
        t = ((x-start) if x > start else (L-start+x)) / 2
        if t <= T:
            num += int((T-t) / (L/2) + eps)+1
    else:
        t = ((start-x) if start > x else (L+start-x))/2
        if t <= T:
            num -= int((T-t) / (L/2) + eps)+1

n = (start+T*(1 if direction==1 else -1))%L
i = N-1-_a[::-1].index(n) if direction==1 else _a.index(n)
i = (i-num)%N
print(*(_a[i:]+_a[:i]), sep="\n")