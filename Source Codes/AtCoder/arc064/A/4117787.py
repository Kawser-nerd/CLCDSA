N, x = map(int, input().split())
l = list(map(int, input().split()))

before = sum(l)
l[0] = min(x, l[0])
for i in range(1, N):
    s = l[i-1]+l[i]
    if s > x:
        l[i] = x-l[i-1]

print(before-sum(l))