S = input()

ans = 0
memo = []
for i in range(1 << len(S)-1):
  tmp = S[0]
  for j in range(len(S)-1):
    if ((i >> j) & 1) == 1:
      tmp += "+"
    tmp += S[j+1]
  if tmp not in memo:
    ans += eval(tmp)
    memo.append(tmp)
print(ans)