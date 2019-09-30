n = int(input())
if n%2: print((n-1)*(n-1)//2)
else: print((n-2)*n//2)
for i in range(1,n):
    for j in range(i+1,n+1):
        if i+j!=n+1-n%2: print(i,j)