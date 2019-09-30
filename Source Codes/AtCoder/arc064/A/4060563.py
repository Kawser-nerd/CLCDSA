n,x = (int(i) for i in input().split())
a = list(int(i) for i in input().split())
copy = []
for num in a:
    copy.append(num)
    
for i in range(n-1):
    if i==0:
        if a[i]>x:
            a[i]=x
    if a[i]+a[i+1]>x:
        a[i+1] = x-a[i]

print(sum(copy)-sum(a))