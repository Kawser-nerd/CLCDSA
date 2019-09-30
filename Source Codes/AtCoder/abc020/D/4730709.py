import itertools
N,K=map(int,input().split())
mod=10**9+7
def tousum(start,finish):
    finish-=finish%start
    kousu=finish//start
    return (kousu*(finish+start))//2
Ktmp=K
D=dict()
index=2
while(index*index<=K):
    if Ktmp%index==0:
        D[index]=0
        while(True):
            if Ktmp%index==0:
                Ktmp=Ktmp//index
                D[index]+=1
            else:
                break
    index+=1
if Ktmp>1:
    D[Ktmp]=1
prime=sorted([p for p in D])
division=set()
index=1
while(index*index<=K):
    if K%index==0:
        division.add(index)
        division.add(K//index)
    index+=1
division=sorted(list(division))
ans=0
for d in division:
    primelist=[]
    for p in prime:
        if (K//d)%p==0:
            primelist.append(p)
    gK=len(primelist)
    tmp=0
    for seq in itertools.product(range(2),repeat=gK):
        fugou=(-1)**(sum(seq)%2)
        aiu=1
        for i in range(gK):
            if seq[i]==1:
                aiu=aiu*primelist[i]
        tmp+=fugou*tousum(aiu*d,N)
        tmp%=mod
    ans+=tmp*(K//d)
    ans%=mod
print(ans)