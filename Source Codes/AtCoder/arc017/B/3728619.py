N, K = map(int, input().split())

i0 = 0
r = 0
a = 0
for _ in range(N):
    i = int(input())
    if i>i0:
        r += 1
    else:
        r = 1
    if r >= K:
        a += 1
    i0 = i
print(a)