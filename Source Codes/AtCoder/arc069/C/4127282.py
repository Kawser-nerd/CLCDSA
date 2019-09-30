from collections import deque
def inpl(): return list(map(int, input().split()))

N = int(input())
A = inpl()
X = sorted([(a, i) for i, a in enumerate(A, start=1)], key=lambda x: [x[0], -x[1]])
answer = [0]*(N+1)
a, i = X.pop()

for c in range(1, N):
    b, j = X.pop()
    answer[i] += (a-b)*c
    i = min(i, j)
    a = b
answer[i] += a * N

print(*answer[1:], sep="\n")