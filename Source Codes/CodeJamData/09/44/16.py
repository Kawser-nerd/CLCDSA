from math import *
f = open('D_Rnd2.in', 'r')
out=open('D_Rnd2.out','w')
cases = int(f.readline()[:-1])

def dist(x1,y1,x2,y2):
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))

def calc(x1,y1,x2,y2,r1,r2):
    #print (dist(x1,y1,x2,y2)+r1/1.0+r2/1.0)/2.0
    return (dist(x1,y1,x2,y2)+r1/1.0+r2/1.0)/2.0


for case in range(1,cases+1):
    n = int(f.readline()[:-1])
    out.write("Case #"+str(case)+": ")
    if n==1:
        s=f.readline()[:-1].split()
        arr=[int(x)/1.0 for x in s]
        arr[2]=arr[2]/1.0
        out.write('%.8f'%arr[2]+"\n")
        print '%.8f'%arr[2]
    if n==2:
        s=f.readline()[:-1].split()
        arr=[int(x)/1.0 for x in s]
        s=f.readline()[:-1].split()
        arr1=[int(x)/1.0 for x in s]
        ret=max(arr[2],arr1[2])/1.0
        out.write('%.8f'%ret+"\n")
        
        print '%.8f'%ret
    if n==3:
        s=f.readline()[:-1].split()
        a=[int(x)/1.0 for x in s]
        s=f.readline()[:-1].split()
        b=[int(x)/1.0 for x in s]
        s=f.readline()[:-1].split()
        c=[int(x)/1.0 for x in s]
        
        
        r1=max(calc(a[0],a[1],b[0],b[1],a[2],b[2]),c[2])
        r2=max(calc(a[0],a[1],c[0],c[1],a[2],c[2]),b[2])
        r3=max(calc(c[0],c[1],b[0],b[1],c[2],b[2]),a[2])
        ret=min(min(r1,r2),r3)
        
        out.write('%.8f'%ret+"\n")
        print '%.8f'%ret