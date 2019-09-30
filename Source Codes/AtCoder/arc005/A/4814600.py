N = int( input())
W = list( input().split())
W[-1] = W[-1][:-1]
ans = 0
for i in range(N):
    if W[i] == "TAKAHASHIKUN" or W[i] == "Takahashikun" or W[i] == "takahashikun":
        ans += 1
print( ans)