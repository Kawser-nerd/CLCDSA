N = int(input())
As = [int(input()) for i in range(N)]

if As[0] != 0:
    # ???
    print(-1)
    exit()

ans = 0
for i in reversed(range(1, N)):
    if As[i - 1] + 1 < As[i]:
        # ???
        ans = -1
        break
    elif As[i - 1] + 1 == As[i]:
        # X[i-1]?X[i]??1???????
        ans += 1
    else:
        # X[i-As[i]]?????As[i]???????
        ans += As[i]

print(ans)