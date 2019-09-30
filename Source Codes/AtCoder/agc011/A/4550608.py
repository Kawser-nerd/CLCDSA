N,C,K = map(int,input().split())
T = []
for i in range(N):
    T.append(int(input()))
T.sort()
i = 0
ans = 0
while i < N:
    Ti = T[i]
    cnt = 0
    while i < N and T[i] <= Ti + K and cnt < C:
        i += 1
        cnt += 1
    ans += 1
print(ans)