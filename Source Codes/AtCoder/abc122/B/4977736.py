str = input()

max = 0
cnt = 0
for i in str:
  if (i == 'A' or i == 'C' or i == 'G' or i == 'T'):
    cnt += 1
    if (cnt >= max):
      max = cnt
  else:
    cnt = 0

print(max)