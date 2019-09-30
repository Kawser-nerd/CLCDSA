n, x = map(int, input().split())

ans = [i for i in range(1, 2*n)]

if x == 1 or x == 2*n - 1:
    print("No")
    exit()

print("Yes")
ans[n-1], ans[x-1] = ans[x-1], ans[n-1]
ans[n-2], ans[0] = ans[0], ans[n-2]
ans[n], ans[2*n-2] = ans[2*n-2], ans[n]

if n == 2:
    for i in ans:
        print(i)
    exit()

if x < 2*n-2:
    ans[n-3], ans[2*n-3] = ans[2*n-3], ans[n-3]
else:
    ans[n+1], ans[1] = ans[1], ans[n+1]

for i in ans:
    print(i)