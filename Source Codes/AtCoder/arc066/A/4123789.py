N=int(input())

ans=None
tmp=0
z=1
if(N%2==0):
    tmp=int(N/2)
    ans=[2 for i in range(tmp)]
    A=map(int,input().split())
    for i in A:
        if(int(i/2)<=int(N/2)):
            ans[int(i/2)-1]-=1
        else:
            print(0)
            exit() 
else:
    tmp=int(N/2)
    ans=[2 for i in range(tmp)]
    z=0
    A=map(int,input().split())
    for i in A:
        if(i==0):
            z=1
            continue
        if(int(i/2)<=int(N/2)):
            ans[int(i/2)-1]-=1
        else:
            print(0)
            exit()
output=2**(tmp)%(10**9+7)
for i in ans:
    if(i!=0):
        output=0

print(output*z)