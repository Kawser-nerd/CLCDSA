N, x = map(int, input().split())
if x == 1 or x == 2 * N - 1:
    print("No")
    exit()

print("Yes")
if N == 2:
    print(1)
    print(2)
    print(3)
    exit()

ans = [-1] * (2 * N - 1)
if x == 2:
    ans[N - 2:N + 2] = [3, 2, 1, 4]
    tmp = 5
    for i in range(2 * N - 1):
        if ans[i] != -1:
            continue
        else:
            ans[i] = tmp
            tmp += 1


else:
    ans[N - 2:N + 2] = [x - 1, x, x + 1, x - 2]
    tmp = x + 2
    for i in range(2 * N - 1):
        if ans[i] != -1:
            continue
        else:
            if tmp >= 2 * N:
                tmp = 1
            ans[i] = tmp
            tmp += 1

for a in ans:
    print(a)