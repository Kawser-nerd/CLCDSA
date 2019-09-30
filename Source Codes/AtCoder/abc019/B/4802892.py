s = input()
tmp = s[0]
cnt=0
for x in s:
  if tmp == x:
    cnt += 1
  else:
    print(tmp+str(cnt),end='')
    cnt = 1
  tmp = x
if cnt != 0:
  print(tmp+str(cnt))