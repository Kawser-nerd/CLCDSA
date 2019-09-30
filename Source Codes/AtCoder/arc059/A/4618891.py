N = int(input())
A = [int(i) for i in input().split()]

ans = (200**2)*100
     
for i in range(-100,101):
    tmp = 0
    for j in range(N):
        tmp += (A[j]-i)**2
    ans = min(ans,tmp)
print(ans)