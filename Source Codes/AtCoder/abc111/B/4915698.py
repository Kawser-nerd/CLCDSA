n = int(input())
num = [111, 222, 333, 444, 555, 666, 777, 888, 999]
min_ = 111
ans = 0
for i in num:
  if i-n<0:
    None
  else:
    if min_ > i-n:
      ans = i
print(ans)