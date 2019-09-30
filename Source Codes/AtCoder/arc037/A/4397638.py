N=int(input())
ans=0
m=list(map(int,input().split()))

for i in range(N):
    if m[i]<80:
        ans+=(80-m[i])
print(ans)