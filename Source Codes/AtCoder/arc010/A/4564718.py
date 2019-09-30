n,m,a,b=map(int,input().split())
d=n
for i in range(m):
    c=int(input())
    if d<=a:
        d+=b
    d-=c
    if d<0:
        print(i+1)
        break
else:
    print("complete")