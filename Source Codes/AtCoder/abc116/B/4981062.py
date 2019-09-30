s = [int(input())]

cnt = 1
while True:
  cnt += 1
  if s[-1]%2==0:
    add = s[-1]/2
  else:
    add = s[-1]*3+1
  if add in s:
    print(cnt)
    break
  else:
    s.append(add)