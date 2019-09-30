K = int(input())

if K == 1:
    print(1)
    print(1)
    exit()

N = 2 * ((K+3)//4)
ans = [[0]*N for i in range(N)]

for i in range(N):
    for j in range(N):
        ans[i][j] = (i+j)%N + 1
        if i%2 and ans[i][j] + N <= K:
            ans[i][j] += N

print(N)
for row in ans:
    print(*row)