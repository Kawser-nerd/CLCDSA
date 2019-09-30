X = int(input())
tmp = 1
while 10**9 > tmp:
  if tmp**4 == X:
    print(tmp)
    break
  else:
    tmp += 1