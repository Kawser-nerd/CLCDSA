import heapq
N = int(input())
a_ls = [int(i) for i in input().split()]
before = []
_sum_before = 0
before_scores = []
after = []
_sum_after = 0
after_scores = []
best = None
for i in range(2*N):
    _sum_before += a_ls[i]
    heapq.heappush(before, a_ls[i])
    _sum_after += a_ls[-i-1]
    heapq.heappush(after, -a_ls[-i-1])
    if i >= N:
        _sum_before -= heapq.heappop(before)
        _sum_after -= -heapq.heappop(after)
    if i >= N - 1:
        before_scores.append(_sum_before)
        after_scores.append(_sum_after)
after_scores = after_scores[::-1]
for i in range(N+1):
    score = before_scores[i] - after_scores[i]
    if best is None:
        best = score
    best = score if best < score else best
print(best)