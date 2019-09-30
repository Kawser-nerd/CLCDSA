n=int(input())
a=sorted(map(int,input().split()))
c,d=0,0
for i in range(n-1):
    c+=2*a[i]
    if c<a[i+1]:
        d=i+1
print(n-d)