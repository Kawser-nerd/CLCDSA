import heapq

n = int(input())
a = [0] + list(map(int, input().split())) #index??
selectleft, selectright= [], []
leftscore, rightscore = [], []
for i in range(1,n+1): heapq.heappush(selectleft, a[i]) # selectleft???????????
leftscore.append(sum(selectleft)) # ??n??n?????
for i in range(n+1,2*n+1): # n+1~n+n?????????
    heapq.heappush(selectleft, a[i])
    tmpscore = leftscore[-1] + a[i]
    poped = heapq.heappop(selectleft)
    tmpscore -= poped
    leftscore.append(tmpscore)
for i in range(2*n+1,3*n+1):
    heapq.heappush(selectright, (-1)*a[i]) # selectright???????????
rightscore.append(sum(selectright)*(-1))
for i in range(2*n,n,-1):
    heapq.heappush(selectright, (-1)*a[i])
    tmpscore = rightscore[-1] + a[i]
    poped = heapq.heappop(selectright) * (-1)
    tmpscore -= poped
    rightscore.append(tmpscore)
rightscore.reverse()
print(max(map(lambda x,y:x-y, leftscore, rightscore)))