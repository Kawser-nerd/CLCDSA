import math

N,M=map(int,input().split())
dic={}
for i in range(2,int(M**0.5)+1):
    if M%i==0:
        dic.setdefault(i,1)
        M//=i
        while M%i==0:
            dic[i]+=1
            M//=i
    if M==1: break

if M!=1: dic[M]=1


ans=1
for k in dic.keys():
    x=dic[k]
    tmp=1
    for i in range (N,x+N):
        tmp*=i
    ans*=tmp//math.factorial(x)
    ans%=1000000007
print(ans%1000000007)