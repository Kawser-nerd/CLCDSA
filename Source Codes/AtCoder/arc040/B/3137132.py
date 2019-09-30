N,R = map(int,input().split())
S = list(input())
r = S.count('.')

ans = 0
for i in range(N):
    p = S[i:i+R].count('.')
    if r == 0:
      ans=0
      break
    if p == r:
        ans += 1
        break
    if S[i] == '.':
        for j in range(i,i+R):
            S[j] = 'o'
        r -= p
        ans += 1
    ans += 1
print(ans)