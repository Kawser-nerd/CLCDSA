n,q=map(int,input().split())
s=str(input())
a=[0]*(n+1)
a[0]=0
for i in range(n):
    if s[i:i+2]=="AC":
        a[i+1]=a[i]+1
    else:
        a[i+1]=a[i]+0
for i in range(q):
    b,c=map(int,input().split())
    print(int(a[c-1]-a[b-1]))