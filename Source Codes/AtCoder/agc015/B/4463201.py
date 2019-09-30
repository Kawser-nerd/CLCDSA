S = input()
N = len(S)
ans = 0
for k in range(N):
    if S[k] == "U":
        ans += N-k-1
    else:
        ans += 2*(N-k-1)
S = S[::-1]

for k in range(N):
    if S[k] == "D":
        ans += N-k-1
    else:
        ans += 2*(N-k-1)
print(ans)