S = list(str(input()))
T = list(str(input()))
moji = "abcdefghijklmnopqrstuvwxyz"
tmp_1 = []
tmp_2 = []
for i in range(26):
  count = S.count(moji[i])
  tmp_1.append(count)
for i in range(26):
  count = T.count(moji[i])
  tmp_2.append(count)
tmp_1.sort()
tmp_2.sort()
if tmp_1 == tmp_2:
  print("Yes")
else:
  print("No")