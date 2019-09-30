N = int(input())
D, X = map(int,input().split())
A = [int(input()) for i in range(N)]
ans = X
# i??????
for i in range(N):
    for j in range(100):
        if j*A[i]+1 <= D:
            ans += 1
print(ans)