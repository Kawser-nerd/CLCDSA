n,m=map(int, input().split())
p=[0]*n
for i in range(m):
    x,y=map(int, input().split())
    p[x-1]+=1
    p[y-1]+=1
ans='YES'
for i in p:
    if i%2==1:ans='NO'
print(ans)