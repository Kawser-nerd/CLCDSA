K=int(input())
if K==1:
    print(1)
    print(1)
    exit()
m=-((-K)//4)
n=2*m
a=[[0 for i in range(n)] for i in range(n)]
for r in range(n):
    for c in range(n):
        p=-1
        if r%2==0:
            p=(r+c)%n
        else:
            p=n+(r+c)%n
        if p>=K:
            p-=n
        a[r][c]=p
s=[[str(a[i][j]+1) for i in range(n)] for j in range(n)]
print(n)
for line in s:
    print(" ".join(line))