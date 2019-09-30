from collections import deque, defaultdict
import heapq

def run_test():
    N, K = map(int, input().split())

    gap_counts = {N : 1}
    gap_counts[N] = 1
    gap_queue = [-N]

    while True:
        gap_size = -heapq.heappop(gap_queue)
        assert gap_size > 0
        gap_count = gap_counts[gap_size]
        del gap_counts[gap_size]
        if K <= gap_count:
            # Done
            return "{} {}".format(gap_size // 2, (gap_size - 1) // 2)
        else:
            K -= gap_count
            left, right = (gap_size - 1) // 2, gap_size // 2
            assert left <= right < gap_size and left + right + 1 == gap_size
            for e in [left, right]:
                if e not in gap_counts:
                    gap_counts[e] = 0
                    heapq.heappush(gap_queue, -e)
                gap_counts[e] += gap_count

for i in range(1, int(input()) + 1):
    print("Case #{}: {}".format(i, run_test()))
