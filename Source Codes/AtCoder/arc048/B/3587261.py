k=[[0]*3for i in range(100001)]
t=[0]*100001
p=[]
n=int(input())
for i in range(n):
    r,h=map(int,input().split())
    p.append([r,h])
    t[r]+=1
    if h==1:
        k[r][0]+=1
    elif h==2:
        k[r][1]+=1
    else:
        k[r][2]+=1
from itertools import accumulate
import operator
t=list(accumulate(t,operator.add))
for i in range(n):
    s=p[i][0]
    u=p[i][1]
    a=t[s-1]
    c=k[s][0]
    d=k[s][1]
    e=k[s][2]
    if u==1:
        print(a+d,n-a-d-c,c-1)
    elif u==2:
        print(a+e,n-a-e-d,d-1)
    else:
        print(a+c,n-a-c-e,e-1)