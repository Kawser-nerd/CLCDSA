import math
y = int(input())
m = int(input())
d = int(input())
A = 365*2014+math.floor(2014/4)-math.floor(2014/100)+math.floor(2014/400)+math.floor(306*6/10)+17-429
if m == 1 or m == 2 :
  y -= 1
  m += 12
  B = 365*y+math.floor(y/4)-math.floor(y/100)+math.floor(y/400)+math.floor(306*(m+1)/10)+d-429
else:
  B = 365*y+math.floor(y/4)-math.floor(y/100)+math.floor(y/400)+math.floor(306*(m+1)/10)+d-429
print(A-B)