n,m=map(int,input().split())
c=0
d=0
a=0
for i in range(n):
    s=int(input())
    if c<s:
        c=s
        d+=1
    else:
        c=s
        a+=max(0,d-m+1)
        d=1
print(a+max(0,d-m+1))