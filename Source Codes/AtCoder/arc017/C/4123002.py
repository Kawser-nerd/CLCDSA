iipt=lambda:int(input())
miipt=lambda:list(map(int, input().split()))

n,x=miipt()
w1=[iipt() for i in range((n+1)//2)]
w2=sorted([iipt() for i in range(n//2)])
ans=0

from collections import defaultdict
d1=defaultdict(int)
d2=defaultdict(int)

for k in range(2**len(w1)):
    W=sum(w1[i] for i in range(len(w1)) if k>>i&1)
    d1[W]+=1
    #print(bin(k),W)
for k in range(2**len(w2)):
    W=sum(w2[i] for i in range(len(w2)) if k>>i&1)
    d2[W]+=1
    #print(bin(k),W)
W2=sorted(d2.keys())
for w, m in d1.items():
    ans+=m*d2[x-w]
 
print(ans)