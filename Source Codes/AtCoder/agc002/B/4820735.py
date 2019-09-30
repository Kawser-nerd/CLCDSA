N, M = map(int, input().split())
red = [0] * N
red[0] = 1
num = [1] * N
for _ in range(M):
    x, y = map(int, input().split())
    num[x - 1] -= 1
    num[y - 1] += 1
    if red[x - 1] == 1:
        red[y - 1] = 1
        if num[x - 1] == 0:
            red[x - 1] = 0
print(sum(red))