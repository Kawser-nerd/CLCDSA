N = int(input())
S = input()

ans = 0
for sakaime in range(N):
    left = set(S[:sakaime])
    right = set(S[sakaime:])
 
    cnt = len(left.intersection(right))
    ans = max(ans, cnt)

print(ans)