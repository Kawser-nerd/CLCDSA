N, S, T = map(int, input().split())
W = int(input())
bestCnt = 0
if S <= W and W <= T:
    bestCnt += 1

for i in range(N - 1):
    W += int(input())
    if S <= W and W <= T:
        bestCnt += 1
print(bestCnt)