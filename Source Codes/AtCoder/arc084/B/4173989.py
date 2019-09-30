from collections import deque

K = int(input())
dp = [float("inf")]*(K+1)
dq = deque([(1, 1)])
popleft, append, append_left = dq.popleft, dq.append, dq.appendleft

while dq:
    v, cost = popleft()
    if v == 0:
        print(cost)
        exit()
    if dp[v] < cost:
        continue
    plus_10, plus_1 = (v*10)%K, (v+1)%K
    if dp[plus_10] > cost:
        dp[plus_10] = cost
        append_left((plus_10, cost))
    if dp[plus_1] > cost+1:
        dp[plus_1] = cost+1
        append((plus_1, cost+1))