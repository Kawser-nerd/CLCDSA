S = input()
n = len(S)
ans = n

for i in range(n-1):
    if S[i+1] != S[i]:
        ans = min(ans, max(i+1,n-i-1))

print(ans)