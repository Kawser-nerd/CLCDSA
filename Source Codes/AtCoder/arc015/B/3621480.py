n=int(input())
a=[0,0,0,0,0,0]
for x in range(n):
    maxx,minn=map(float,input().split(' '))
    if(maxx>=35):
        a[0]=a[0]+1
    if(maxx>=30 and maxx<35):
        a[1]=a[1]+1
    if(maxx>=25 and maxx<30):
        a[2]=a[2]+1
    if(minn>=25):
        a[3]=a[3]+1
    if(maxx>=0 and minn<0):
        a[4]=a[4]+1
    if(maxx<0):
        a[5]=a[5]+1
print ("%d %d %d %d %d %d"%(a[0],a[1],a[2],a[3],a[4],a[5]))