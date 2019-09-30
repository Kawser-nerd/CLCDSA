N = int(input())
a = [int(input()) for _ in range(N)]

next_light = 1
li = [0]
count = 0
for i in range(N):
    next_light = a[next_light-1]
    count += 1
    if 2 == next_light:
        break
if N == count:
    print(-1)
else:
    print(count)