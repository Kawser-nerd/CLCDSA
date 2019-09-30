N, R = map(int, input().split())
S = list(input())

ans = 0
for i in range(N):
    if S[i] == ".":
        ans = max(ans, i - R + 1)

i = 0
while i < N:
    if S[i] == ".":
        ans += 1
        i += R-1
    i += 1

print(ans)