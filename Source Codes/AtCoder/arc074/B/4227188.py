import heapq
n=int(input())
A=list(map(int,input().split()))
que_left,que_right=[],[]
left,right=[-float("inf")]*(3*n),[float("inf")]*(3*n)
for i in range(n):
    heapq.heappush(que_left,A[i])
    if i==0:
        left[i]=A[i]
    else:
        left[i]=left[i-1]+A[i]
for i in range(n,2*n):
    heapq.heappush(que_left,A[i])
    tmp=heapq.heappop(que_left)
    left[i]=left[i-1]+A[i]-tmp
for i in range(2*n,3*n)[::-1]:
    heapq.heappush(que_right,-A[i])
    if i==3*n-1:
        right[i]=A[i]
    else:
        right[i]=right[i+1]+A[i]
for i in range(n,2*n)[::-1]:
    heapq.heappush(que_right,-A[i])
    tmp=heapq.heappop(que_right)
    right[i]=right[i+1]+A[i]+tmp
ans=-float("inf")
for i in range(n-1,2*n):
    ans=max(ans,left[i]-right[i+1])
print(ans)