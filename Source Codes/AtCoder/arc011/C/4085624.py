from collections import defaultdict, deque
def inpl(): return list(map(int, input().split()))
first, last = input().split()
N = int(input())
S = [first] + [input() for _ in range(N)] + [last]
L = len(S[0])
candidate = [s for s in range(1, N+2)]

def path(p, q):
    return sum([sp != sq for sp, sq in zip(S[p], S[q])]) <= 1
        
B = [-1 for _ in range(N+2)]
C = [10**4 for _ in range(N+2)]

C[0] = 0
Q = deque([0])

while Q:
    p = Q.popleft()
    next_candidate = []
    for q in candidate:
        if not path(p, q):
            next_candidate.append(q)
            continue
        B[q] = p
        C[q] = C[p] + 1
        Q.append(q)
        if q == N+1:
            Q = []
            break
    candidate = next_candidate


if B[-1] != -1:
    ans = []
    i = -1
    while i:
        ans.append(S[i])
        i = B[i]
    ans.append(S[0])
    print(len(ans)-2)
    print(*ans[::-1], sep="\n")
else:
    print(-1)