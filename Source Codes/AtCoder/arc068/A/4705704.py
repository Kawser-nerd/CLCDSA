x = int(input())
y = x//11
x %= 11
z = 0
if 0 < x < 7:
  z = 1
elif 6 < x < 11:
  z = 2
print(y*2+z)