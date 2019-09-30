import heapq

for test_case in xrange(1, int(raw_input()) + 1):
    N = int(raw_input())
    D = [0] * (N + 1)
    L = [0] * (N + 1)

    for i in xrange(N):
        D[i], L[i] = map(int, raw_input().split())

    D[N] = int(raw_input())
    earliest = [-1] * (N + 1)
    earliest[0] = 0
    heap = []
    heapq.heappush(heap, (D[0], D[0] + min(D[0] - earliest[0], L[0])))

    for i in xrange(1, N + 1):
        while heap and heap[0][1] < D[i]:
            heapq.heappop(heap)

        if heap:
            earliest[i] = heap[0][0]
            heapq.heappush(heap, (D[i], D[i] + min(D[i] - earliest[i], L[i])))
    
    print "Case #{0}: {1}".format(test_case, "YES" if earliest[N] != -1 else "NO")
