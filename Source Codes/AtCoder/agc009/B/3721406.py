import sys
from heapq import heapify,heappush,heappop
sys.setrecursionlimit(10**7)
input=sys.stdin.readline
N=int(input())
List=[[] for i in range(N)]
for i in range(1,N):
  a=int(input())
  List[a-1].append(i)

def f(x):
  if len(List[x])==0:
    return 0
  L=[]
  heapify(L)
  for a in List[x]:
    heappush(L,f(a))
  n=len(L)
  res=0
  for i in range(n):
    b=heappop(L)
    res=max(res,b+n-i)
  return res
print(f(0))