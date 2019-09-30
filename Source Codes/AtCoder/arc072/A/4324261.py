N=int(input())

L=list(map(int,input().split()))

Pnum=0
Psum=0
if L[0]>=1:
    Pnum=L[0]
else:
    Psum=1-L[0]
    Pnum=1
for i in range(1,N):
    if i%2==1:
        if Pnum+L[i]<=-1:
            Pnum=Pnum+L[i]
        else:
            Psum+=(Pnum+L[i]+1)
            Pnum=-1
    else:
        if Pnum+L[i]>=1:
            Pnum=Pnum+L[i]
        else:
            Psum+=(1-Pnum-L[i])
            Pnum=1
            
Mnum=0
Msum=0
if L[0]<=-1:
    Mnum=L[0]
else:
    Msum=L[0]+1
    Mnum=-1
for i in range(1,N):
    if i%2==0:
        if Mnum+L[i]<=-1:
            Mnum=Mnum+L[i]
        else:
            Msum+=(Mnum+L[i]+1)
            Mnum=-1
    else:
        if Mnum+L[i]>=1:
            Mnum=Mnum+L[i]
        else:
            Msum+=(1-Mnum-L[i])
            Mnum=1

print(min(Psum,Msum))