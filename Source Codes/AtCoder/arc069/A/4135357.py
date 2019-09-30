N,M=map(int,input().split())

ans=0
if(M//2>=N):
        ans+=N
        M-=N*2
        ans+=M//4
else:
        ans+=M//2

print(ans)