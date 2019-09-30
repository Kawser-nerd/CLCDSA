N, X = map(int, input().split())
m = [int(input()) for _ in range(N)]

count = N
X -= sum(m)
while True:
    X -= min(m)
    if X < 0:
        break
    count += 1

print(count)