a=list(map(int,input().split()))
a=sorted(a)

c=a[0]%2+a[1]%2+a[2]%2
ans=0
if(c==0 or c==3):
    ans+=a[2]-a[0]+a[2]-a[1]
    ans//=2
else:
    if(c==1):
        for i in range(3):
            if(a[i]%2==0):
                a[i]+=1
    elif(c==2):
        for i in range(3):
            if(a[i]%2!=0):
                a[i]+=1
    ans+=1
    ans+=(a[2]-a[0]+a[2]-a[1])//2

print(ans)