from heapq import heappush, heappop
n=int(input())
a=list(map(int, input().split()))
q1=[]
q2=[]
s1=[]
s2=[]
for i in range(n):
    heappush(q1, a[i])
s1.append(sum(a[0:n]))
for ai in a[n:2*n]:
    heappush(q1, ai)
    m=heappop(q1)
    s1.append(s1[-1]+ai-m)
a=a[::-1]
for i in range(n):
    heappush(q2, -a[i])
s2.append(-sum(a[0:n]))
for ai in [-i for i in a[n:2*n]]:
    heappush(q2, ai)
    m=heappop(q2)
    s2.append(s2[-1]+ai-m)
ans=s1[0]+s2[-1]
for i in range(n+1):
    ans=max(s1[i]+s2[-i-1], ans)
print(ans)