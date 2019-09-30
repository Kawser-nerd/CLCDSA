n, m = map(int, input().split())
ans = 0
box = [1] * n
flag = [False] * n
flag[0] = True
for i in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    box[x] -= 1
    box[y] += 1
    if flag[x]:
        flag[y] = True
    if box[x] == 0:
        flag[x] = False
print(sum(flag))