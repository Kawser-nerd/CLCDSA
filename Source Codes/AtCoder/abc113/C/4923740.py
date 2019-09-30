n,m=map(int,input().split())
p=[]
for i in range(1,m+1):
    a=list(map(int,input().split()))
    a.append(i)
    p.append(a)
    
p.sort()

for i in range(m):
    if i==0 or p[i][0] != p[i-1][0]:
        cnt=1
    else:
        cnt+=1
    p[i].append(cnt)

p.sort(key= lambda x: x[2])

for i in range(m):
    print("{:06}{:06}".format(p[i][0],p[i][3]))