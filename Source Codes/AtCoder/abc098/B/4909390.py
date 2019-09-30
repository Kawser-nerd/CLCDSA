N = int(input())
S = input()

ans = -1
for i in range(N):
    x = len(set(list(S[:i]))&set(list(S[i:])))
    if x > ans:
        ans = x

print(ans)