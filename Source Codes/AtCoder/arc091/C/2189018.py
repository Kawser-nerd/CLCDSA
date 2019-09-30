N, A, B = map(int, input().split())

if N-B+1 < A or A < (N + B-1) // B:
    print(-1)
    exit(0)

res = []
r = []
cnt = 0
for i in range(N):
    r.append(N-i)
    if N-i <= A-cnt or len(r) == B:
        res.append(r)
        r = []
        cnt += 1

if r:
    res.append(r)
ans = []
for r in reversed(res):
    ans.extend(r)
print(*ans)