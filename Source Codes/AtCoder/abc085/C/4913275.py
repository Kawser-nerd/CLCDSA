N, Y = map(int, input().split())

flag = False
for x in range(0, N+1):
    for y in range(0, N+1):
        if x + y > N:
            break
        z = N - x - y
        if Y == 10000 * x + 5000 * y + 1000 * z:
            flag = True

        if flag:
            break
    if flag:
        break
if flag:
    print(x, y, z)
else:
    print("-1 -1 -1")