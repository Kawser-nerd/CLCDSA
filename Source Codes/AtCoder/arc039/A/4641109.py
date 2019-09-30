a,b = map(str,input().split())
ans = -1*float('inf')
A = int(a)
B = int(b)
for i in range(1,10):
    i = str(i)
    A1 = int(i + a[1]+a[2])
    for j in range(10):
        j = str(j)
        A2 = int(a[0]+j+a[2])
        A3 = int(a[0]+a[1]+j)
        ans = max(ans,A1-B,A2-B,A3-B)
for i in range(1,10):
    i = str(i)
    B1 = int(i + b[1]+b[2])
    for j in range(10):
        j = str(j)
        B2 = int(b[0]+j+b[2])
        B3 = int(b[0]+b[1]+j)
        ans = max(ans,A-B1,A-B2,A-B3)
print(ans)