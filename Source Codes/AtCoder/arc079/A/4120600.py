import heapq
import sys
input = sys.stdin.readline
N, M = map(int, input().split())
cand_1 = []
cand_2 = []
for _ in range(M):
    a, b = map(int, input().split())
    if a == 1:
        cand_1.append(b)
    elif b == N:
        cand_2.append(a)

ans = "IMPOSSIBLE"
heapq.heapify(cand_1)
heapq.heapify(cand_2)


while len(cand_1) != 0 and len(cand_2) != 0:
    if cand_1[0] < cand_2[0]:
        heapq.heappop(cand_1)
    elif cand_1[0] > cand_2[0]:
        heapq.heappop(cand_2)
    else:
        ans = "POSSIBLE"
        break
print(ans)