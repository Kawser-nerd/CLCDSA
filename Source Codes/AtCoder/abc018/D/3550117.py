import itertools
import numpy as np
N,M,P,Q,R = map(int,input().split())
choco = np.zeros((N,M))
for i in range(R):
    x,y,z = map(int,input().split())
    choco[x-1][y-1]=z

seq = [i for i in range(N)]
ans = 0
for girls in itertools.combinations(seq,P):
    happiness = np.sum(choco[list(girls)],axis=0)
    happiness = sorted(happiness,key=lambda x:-x)
    ans = max(ans,sum(happiness[:Q]))
print(int(ans))