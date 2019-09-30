N,M=map(int,input().split())


ans=0

for i in range(1,int(M**0.5)+1):
    if M%i==0:
        if M/i>=N: ans=max(ans,i)
        if i>=N: ans=max(ans,M//i)

print(ans)