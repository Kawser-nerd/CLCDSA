import math
N, H = map(int, input().split())
a = []
b = []
for i in range(N):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)

throw = 0
throw_count = 0
max_a = max(a)
b.sort(reverse=1)
for i in b:
    if i < max_a:
        break

    throw += i
    throw_count += 1
    if throw >= H:
        print(throw_count)
        exit()

print(math.ceil((H - throw)/max_a) + throw_count)