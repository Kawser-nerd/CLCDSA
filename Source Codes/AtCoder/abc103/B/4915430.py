S = input()
T = input()
ans = 'No'
if S == T:
    ans = 'Yes'
for i in range(len(S)):
    S = S[-1] + S
    S = S[:-1]
    if S == T:
        ans = 'Yes'
print(ans)