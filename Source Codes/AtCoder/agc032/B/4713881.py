n=int(input())
a=[]
for i in range(1,n+1):
    for j in range(i,n+1-n%2):
        if j!=i!=n-j+1-n%2:
            a.append((i,j))
if n%2:
    a+=[(i,n)for i in range(1,n)]
print(len(a))
for t in a:
    print(*t)