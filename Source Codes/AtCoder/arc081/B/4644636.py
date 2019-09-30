n=int(input())
s=input()
t=input()
mod=10**9+7

l=[]
k=0
i=0
while i<n:
    if s[i]==t[i]:
        if k==0:
            l.append(3)
        elif k==1:
            l.append(2)
        else:
            l.append(1)
        k=1
        i+=1
    else:
        if k==0:
            l=l+[3,2]
        elif k==1:
            l=l+[2,1]
        else:
            l=l+[3,1]
        k=2
        i+=2
ans=1
for i in range(n):
    ans*=l[i]
print(ans%mod)