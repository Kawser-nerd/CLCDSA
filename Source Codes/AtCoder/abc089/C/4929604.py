n=int(input())
s=[input()[0] for _ in range(n)]
a=['M','A', 'R', 'C', 'H']
import itertools
num=[0]* 5
for i in range(5):
    num[i]=s.count(a[i])
ans=0
if num.count(0)<=2:
    m=[x for x in num if x > 0]
    p=list(itertools.combinations(m, 3))
    for j in range(len(p)):
        ans+=p[j][0]*p[j][1]*p[j][2]
print(ans)