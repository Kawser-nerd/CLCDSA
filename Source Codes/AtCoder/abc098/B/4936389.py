N = int(input())
S = input()
import string
abcs = string.ascii_lowercase

ans = 0
for sakaime in range(N):
    cnt = 0
    left = S[:sakaime]
    right = S[sakaime:]
    for alpha in abcs:
        if alpha in left and alpha in right:
            cnt += 1
    ans = max(ans, cnt)
    
print(ans)