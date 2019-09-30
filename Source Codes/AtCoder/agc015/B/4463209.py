S = input()
N = len(S)

ans = 0
for (i,c) in enumerate(S):
    if c == 'U':
        ans += (N-i-1) + 2*i
    else:
        ans += i + 2*(N-i-1)
print(ans)