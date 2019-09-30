x = int(input())
count = 0
a = x//11 #2?????????11??????
count += 2*a
if(x%11 != 0):  
  b = x - 11*a
  if(1<=b<=6): count += 1
  else: count += 2
print(count)