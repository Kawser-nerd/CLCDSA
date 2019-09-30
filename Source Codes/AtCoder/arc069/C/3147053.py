import heapq
N = int(input())
A = list(map(int, input().split()))

# (ai, i)??????
A = sorted([(ai, i) for i, ai in enumerate(A, start=1)], reverse=True)

# ???N+1?????(0, 0)??????
A.append((0, 0))

# ??
ans = [0] * (N + 1)
y = []
for i in range(N):
    heapq.heappush(y, A[i][1])
    ans[y[0]] += (i + 1) * (A[i][0] - A[i + 1][0])

print(*ans[1:], sep="\n")