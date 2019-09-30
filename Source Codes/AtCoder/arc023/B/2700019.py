R, C, D = map(int, input().split())
A = [list(map(int, input().split())) for i in range(R)]

ans = 0
for r in range(R):
    for c in range(C):
        if r + c <= D and (D - (r+c)) % 2 == 0:
            ans = max(ans, A[r][c])

print(ans)