from collections import deque
K = int( input())
V = [0]*K
q = deque([(1,1)])
while q:
    x, r = q.popleft()
    if x == 0:
        ans = r
        break
    if V[x] == 1:
        continue
    V[x] = 1
    if V[10*x%K] == 0:
        q.appendleft((10*x%K, r))
    if V[(x+1)%K] == 0:
        q.append(((x+1)%K, r+1))
print(ans)