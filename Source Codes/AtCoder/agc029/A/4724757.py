S = input()
white = 0
for i in range(len(S)):
  if S[i] == 'W':
    white += 1
cnt = 0
ans = 0
for i in range(len(S)):
  if S[i] == 'W':
    ans += i-cnt
    cnt += 1
print(ans)