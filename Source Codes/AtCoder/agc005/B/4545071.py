import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
import heapq
n=int(input())
A=list(map(int,input().split()))
idx={}
for i,a in enumerate(A):
    idx[a]=i
hq=[]
right=[n-1]*n
for i in range(n):
    while hq and -hq[0]>A[i]:
        h=-heapq.heappop(hq)
        right[idx[h]]=i-1
    heapq.heappush(hq,-A[i])
hq=[]
left=[0]*n
for i in range(n-1,-1,-1):
    while hq and -hq[0]>A[i]:
        h=-heapq.heappop(hq)
        left[idx[h]]=i+1
    heapq.heappush(hq,-A[i])
ans=0
for i in range(n):
    ans+=A[i]*(i-left[i]+1)*(right[i]-i+1)
print(ans)