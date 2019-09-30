N, L, T = map(int, input().split())
x = ["" for i in range(N)]
w = ["" for i in range(N)]
for i in range(N):
    x[i], w[i] = map(int, input().split())

y = [[i, ""] for i in range(N)]
for i in range(N):
    y[i][1] = (x[i] + (-1)**(w[i]+1)*T) % L

count = 0
for i in range(N):
    if w[0] < w[i]:
        count += (2 * T + L - x[i] + x[0]) // L
    elif w[0] > w[i]:
        count += (2 * T + x[i] - x[0]) // L

if w[0] == 1:
    num = count % N
else:
    num = -count % N

if w[0] == 1:
    y.sort(key=lambda x: (x[1], -x[0]))
else:
    y.sort(key=lambda x: (x[1], x[0]))

for i in range(N):
    if y[i][0] == 0:
        index = i
        break

for i in range(N):
    print(y[(index-num+i) % N][1])