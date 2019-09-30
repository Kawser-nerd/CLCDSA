n, c = map(int, input().split())
*A, = [int(input()) for i in range(n)]
ans = n
for p in range(10):
    for q in range(10):
        if p == q:
            continue
        ans = min(ans, sum([p, q][i%2]+1 != A[i] for i in range(n)))
print(ans*c)