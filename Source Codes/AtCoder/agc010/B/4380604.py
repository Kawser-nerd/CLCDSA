n=int(input())
a=list(map(int, input().split()))
ans='YES'
suma=sum(a)
i=suma/(n*(n+1)//2)
a2=[a[j]-a[j-1]-i for j in range(n)]
for i in a2:
    if i%n!=0 or i>0:ans='NO'
print(ans)