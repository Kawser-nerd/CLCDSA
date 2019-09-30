N = int(input())
S = input()
ans = 0
for i in range(1, N):
    x = set(S[:i+1])
    y = set(S[i+1:])
    cnt = 0
    for j in x:
        if j in y:
            cnt += 1
    ans = max(ans, cnt)
print(ans)