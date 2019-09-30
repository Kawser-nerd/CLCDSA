S = list(input())
W_i = [i for i,j in enumerate(S) if j == 'W']
W_n = S.count('W')
cur = 0
ans = 0
for i in W_i:
  ans += i-cur
  cur += 1
print(ans)