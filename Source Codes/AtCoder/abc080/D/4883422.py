import sys
 
stdin = sys.stdin
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()
 
n, c = na()
stc = []
for i in range(n):
    stc.append(na())
stc.sort(key=lambda x: (x[2], x[0]))

nstc=[]
for i in range(n):
    if(len(nstc)>0 and nstc[-1][2]==stc[i][2] and nstc[-1][1]==stc[i][0]):
        nstc[-1][1]=stc[i][1]
    else:
        nstc.append(stc[i])
n=len(nstc)
h=[0]*200005
for i in range(n):
    h[2*nstc[i][0]-1]+=1
    h[2*nstc[i][1]]+=-1
for i in range(len(h)-1):
    h[i]+=h[i-1]
print(max(h))