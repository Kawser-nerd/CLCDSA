N=int(input())
A=list(map(int,input().split()))
s=0
t=0
a=0
b=0
for i in range(N):
    s+=A[i]
    if i%2==0:
        if s>=0:
            a+=s+1
            s=-1
    if i%2!=0:
        if s<=0:
            a+=-s+1
            s=1
for j in range(N):
    t+=A[j]
    if j%2!=0:
        if t>=0:
            b+=t+1
            t=-1
    if j%2==0:
        if t<=0:
            b+=-t+1
            t=1
print(min(a,b))