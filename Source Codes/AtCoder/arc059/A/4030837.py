a=int(input())
b=list(map(int,input().split()))
c=sum(b)//a
d=[0,0]
for i in range(a):
    d[0]+=(b[i]-c)**2
    d[1]+=(b[i]-c-1)**2
print(min(d))