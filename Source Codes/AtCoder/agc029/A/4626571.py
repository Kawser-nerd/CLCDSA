S = input()
num, cnt = 0, 0
for k in range(len(S)):
  if S[k] == 'B':
    num += 1
  else:
    cnt += num
print(cnt)