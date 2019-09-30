a=[0,0,1]
n=int(input())
for i in range(3,n):
    b=(a[i-1]+a[i-2]+a[i-3])%10007
    a.append(b)
print(a[n-1])