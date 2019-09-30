L = list(map(int,input().split()))
R = list(map(int,input().split()))
ans = 0
for i in range(7):
    ans += max(L[i],R[i])
print(ans)