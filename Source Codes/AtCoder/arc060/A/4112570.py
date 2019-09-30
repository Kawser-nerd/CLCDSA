n, a = list(map(int, input().split()))
xs = list(map(int, input().split()))

na = n*a

DP = [[0]*(na+1) for i in range(n+1)]
DP[0][0] = 1

for _ in range(n):
    x = xs[_]
    next = [[0]*(na+1) for i in range(n+1)]
    for i in range(_+1):
        for j in range(na+1):
            # x???????
            next[i][j] += DP[i][j]
            if j+x <= na:
                next[i+1][j+x] += DP[i][j]
    DP = next

# i?????????i*a???????
ans = 0
for i in range(1,n+1):
    ans += DP[i][i*a]
print(ans)