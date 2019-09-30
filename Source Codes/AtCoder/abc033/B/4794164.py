N = int(input())
l = [input().split() for i in range(N)]
for i in range(N):
    l[i][1] = int(l[i][1])

sm = 0
for i in range(N):
    sm += l[i][1]
sm //= 2

for i in range(N):
    if (l[i][1] > sm):
        print(l[i][0])
        exit(0)
print('atcoder')