import itertools as it
N = int(input())
ps = []
for _ in range(N):
    ps.append(list(map(int,input().split())))
#print(ps)
g = 0
for i in range(N-2):
    p1 = ps[i]
    for (p2,p3) in it.combinations(ps[i+1:], 2):
        #print(p1,p2,p3)
        s = abs((p1[0]-p3[0])*(p2[1]-p3[1])-(p2[0]-p3[0])*(p1[1]-p3[1]))
        if s%2==0 and s!=0:g += 1
        #print('',s,g)
print(g)