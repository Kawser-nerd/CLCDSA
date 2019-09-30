s = int(input())

numset = {s}
for i in range(2, 1000001, 1):
  
  if s % 2 == 0:
    s = s / 2
  else:
    s = (s * 3) + 1
  
  if {s} <= numset:
    print(i)
    break
  else:
    numset.add(s)