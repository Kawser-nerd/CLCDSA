N,K=map(int,input().split())
Sushi=[[int(i) for i in input().split()] for j in range(N)]
Sushi=sorted(Sushi,key=lambda x:x[1],reverse=True)
inp={}
for t,d in Sushi:
    if not t in inp:
        inp[t]=d#??????????????
tasty=0
neta=set()#???????
dup=[]
for i in range(K):
    t,d=Sushi[i]
    tasty+=d
    if t in neta:
        dup.append((t,d))#?????????
    neta.add(t)
    if t in inp:
        del inp[t]
variety=len(neta)
max_tasty=tasty+variety**2
for s,t in sorted(inp.items(),key=lambda x:x[1],reverse=True):
    if len(dup):
        s1,t1=dup.pop()#??????????????
        variety+=1
        tasty=tasty-t1+t
        max_tasty=max(max_tasty,tasty+variety**2)
print(max_tasty)