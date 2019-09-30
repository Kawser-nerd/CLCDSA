from heapq import heappush, heappop
n, k =map(int, input().split())

#????????????
L =[]
for i in range(n):
    t, d = map(int, input().split())
    heappush(L, (-d, t)) #????????,heapq?????????-???

LL=[]
sum = 0
s = set()
for i in range(k):
    d, t = heappop(L)
    if t in s:
        heappush(LL, (-d, t)) #????????????????
    s.add(t)
    sum+=-d

ans = len(s)**2+sum

while L and LL:
    d, t = heappop(L)
    if t not in s:
        s.add(t)
        dd, _ = heappop(LL)
        sum = sum -dd +(-d)
        ans = max(ans, len(s)**2+sum)
print(ans)