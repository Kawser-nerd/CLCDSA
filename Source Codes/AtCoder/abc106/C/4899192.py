S = input()
K = input()

cnt_1 = 0
cnt_aft_1 = None

for s in S:
  if s == '1':
    cnt_1 += 1
  else:
    cnt_aft_1 = s
    break

if len(S) == 1:
  print(S)
elif int(K) <= cnt_1:
  print('1')
else:
  print(cnt_aft_1)