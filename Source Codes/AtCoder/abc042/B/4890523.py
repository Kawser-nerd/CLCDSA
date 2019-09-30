n,l=map(int,input().split())
a=[]
for i in range(n):
    a.append(input())
for j in range(n):
    for i in range(j):
        if a[i]>a[j]:
            b=a[i]
            a[i]=a[j]
            a[j]=b
for i in range(1,n):
    a[0] += a[i]
print(a[0])