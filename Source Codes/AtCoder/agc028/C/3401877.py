n=int(input())
a=[]
b=[]
for i in range(n):
    p,q=map(int,input().split())
    a.append((p,i,0))
    a.append((q,i,1))
a.sort(key=lambda x:x[0])
result=0
l=[0]*n
flag=0
for i in range(n):
    if l[a[i][1]]==1:
        flag=1
        break
    else:
        l[a[i][1]]=1
t=a[0][2]
s=0
for i in range(n):
    s+=a[i][2]-a[0][2]
if s==0:
    flag=1
if flag==1:

    for i in range(n):
        result+=a[i][0]
    print(result)
else:
    if a[n-1][1]==a[n][1]:
        for i in range(n):
            result+=a[i][0]
        result+=min(a[n+1][0]-a[n-1][0],a[n][0]-a[n-2][0])
        print(result)
    else:
        for i in range(n):
            result+=a[i][0]
        result+=a[n][0]-a[n-1][0]
        print(result)