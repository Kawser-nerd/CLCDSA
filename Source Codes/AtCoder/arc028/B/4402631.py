import sys
from heapq import heappop, heappush

fin = sys.stdin.readline
MAX_N = 100000
N, K = [int(elem) for elem in fin().split()]


X_list = tuple(int(elem) for elem in fin().split())
age_to_rank = [None] * (N + 1)
for i, X in enumerate(X_list, start=1):
    age_to_rank[X] = i

max_heap = []
for X in X_list[:K]:
    heappush(max_heap, -X)

print(age_to_rank[-max_heap[0]])
for X in X_list[K:]:
    if X < -max_heap[0]:
        heappop(max_heap)
        heappush(max_heap, -X)
    print(age_to_rank[-max_heap[0]])