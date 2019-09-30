from itertools import*
from numpy import array
n,c=map(int,input().split())

l1=[]
l2=[]
for i in range(n):
    x,v=map(int,input().split())
    l1.append(x)
    l2.append(v)
#print(l1,l2)

ll=array([0]+l1)
lll=array([0]+list(accumulate(l2)))
lr=array([0]+[c-i for i in l1][::-1])
llr=array([0]+list(accumulate(l2[::-1])))
x=lll-ll
y=llr-lr
for i in range(1,n+1):
    x[i]=max(x[i-1],x[i])
    y[i]=max(y[i-1],y[i])
z=array([min(ll[::-1][i],lr[i])for i in range(n+1)])
print(max(x[::-1]+y-z))