import heapq
N=int(input())
s=set()
q=[0,0]
for a in map(int,input().split()):
    if a>q[0]:
        try:
            s.remove(a)
            heapq.heapreplace(q,a)
        except:
            s.add(a)
print(q[0]*q[1])