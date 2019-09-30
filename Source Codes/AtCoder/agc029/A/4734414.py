S = list(input())
B = 0
ans = 0

for i in range(len(S)):
    if S[i] == 'B':
        B += 1
    else:
        ans += B

print(ans)