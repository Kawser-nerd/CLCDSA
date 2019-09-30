N = int(input())
a = [input() for _ in [0]*N]
x, y, count = N, 0, 0

for y in range(N):
    i = a[y][:x].rfind(".")
    if i == -1:
        x = N
    else:
        x = i
        count += 1

print(count)