import heapq
N,A,B = map(int,input().split())
src = list(map(int,input().split()))
if A == 1:
    for v in sorted(src):
        print(v)
    exit()

mem = []
maxv = 0
for i,v in enumerate(src):
    mem.append((v, i))
    if v > maxv: maxv = v
heapq.heapify(mem)
while True:
    v,i = heapq.heappop(mem)
    if B == 0 or (v*A > maxv and B%N == 0):
        heapq.heappush(mem, (v,i))
        break
    maxv = max(maxv, v*A)
    heapq.heappush(mem, (v*A,i))
    B -= 1

MOD = 10**9+7
p = pow(A, B//N, MOD)
while mem:
    v,i = heapq.heappop(mem)
    print((v*p) % MOD)