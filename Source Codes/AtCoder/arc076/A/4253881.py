N,M=map(int,input().split())


ans=1 if(abs(N-M)<2) else 0
n=max(N,M)

fa=0
for i in range(1,n+1):
    fa=ans
    ans=ans*i%(10**9+7)
    
if(N==M):
    ans=(ans*ans*2)%(10**9+7)
else:
    ans=((ans)*fa)%(10**9+7)
print(ans)