N,M = map(int,input().split())

x = [0 for i in range(M)]
y = [0 for j in range(M)]
for k in range(M):
    x[k],y[k] = map(int,input().split())
    x[k] -= 1
    y[k] -= 1

ball = [1 for i in range(N)]
red = [0 for j in range(N)]
red[0] = 1

for i in range(M):
    ball[x[i]] -= 1
    ball[y[i]] += 1
    if red[x[i]] == 1:
        red[y[i]] = 1
    if ball[x[i]] == 0:
        red[x[i]] = 0

print(sum(red))