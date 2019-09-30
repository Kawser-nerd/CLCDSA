from collections import*
input=open(0).readline
h,w,n=map(int,input().split())
d=defaultdict(int)
for _ in range(n):
    a,b=map(int,input().split())
    for i in(0,-1,-2):
        for j in(0,-1,-2):
            d[(a+i,b+j)]+=1
a=[0]*10
for i in d.keys():
    if 0<i[0]<h-1and 0<i[1]<w-1:
        a[d[i]]+=1
a[0]=(h-2)*(w-2)-sum(a)
print(*a,sep='\n')