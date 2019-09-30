n = float(input())
def keisan(x):
  ans = x
  ans += n/(2**(x/1.5))
  return ans
x0 = 0
x3 = 120
while x3 - x0 >10**(-12):
  x1 = (x0*2+x3)/3
  x2 =  (x0+x3*2)/3
  y1 = keisan(x1)
  y2 = keisan(x2)
  if y1 > y2:
    x0 = x1
  else:
    x3 = x2
print(keisan(x3))