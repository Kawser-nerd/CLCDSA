def high(i):
    return max(H - abs(x[i] - Cx) - abs(y[i] - Cy), 0)

N = int(input())
x = []
y = []
h = []
for _ in range(N):
    a, b, c = map(int, input().split())
    x.append(a)
    y.append(b)
    h.append(c)

for i in range(N):
    if h[i] != 0:
        non_zero = i
        break

found = False
for Cx in range(0, 101):
    for Cy in range(0, 101):
        H = h[non_zero] + abs(x[non_zero] - Cx) + abs(y[non_zero] - Cy)
        if all([h[i] == high(i) for i in range(N)]):
            print('{} {} {}'.format(Cx, Cy, H))
            found = True
            break
    if found:
        break