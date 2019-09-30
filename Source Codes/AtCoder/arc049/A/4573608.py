S = input()
A, B, C, D = map(int, input().split())

ans = ''
for i in range(len(S)):
    if i == A or i == B or i == C or i == D:
        ans += '"' + S[i]
    else:
        ans += S[i]
if len(S) == D:
    ans += '"'

print(ans)