N=int(input())
div=[0]*(N+1)

for i in range(1,N+1):
    j=2
    while i!=1:
        if i%j==0:
            i//=j
            div[j]+=1
        else: j+=1

a,b,c,d,e=0,0,0,0,0
for i in range(N+1):
    if div[i]>=74:
        a+=1
        b+=1
        c+=1
        d+=1
        e+=1
    elif div[i]>=24:
        a+=1
        b+=1
        c+=1
        d+=1
    elif div[i]>=14: 
        a+=1
        b+=1
        c+=1
    elif div[i]>=4:
        a+=1
        b+=1
    elif div[i]>=2:
        a+=1

if a<3 or b<2: print(0)
else:
    ans=b*(b-1)*(a-2)//2
    ans+=d*(a-1)
    ans+=c*(b-1)
    ans+=e
    print(ans)