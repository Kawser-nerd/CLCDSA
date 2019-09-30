N,K = map(int,input().split())
hn = [int(input()) for _ in range(N)]
hn.sort()
ans = 10 ** 12
for i in range(N-(K-1)):
    ans = min(ans, hn[i+(K-1)]-hn[i])
print(ans)