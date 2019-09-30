S = list(input())

w_count = 0
ans = 0
for i in range(len(S)):
  if(S[i] == 'W'):
    ans += i - w_count
    w_count += 1
print(ans)