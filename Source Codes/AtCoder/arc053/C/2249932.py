from operator import itemgetter

n = int(input())
ab = []
ac = []
for i in range(n):
  a, b = map(int, input().split())
  b = -b
  aminusb = a + b
  if aminusb < 0:
    ab.append((a, b, aminusb))
  else:
    ac.append((a, b, aminusb))
    
shijo = sorted(ab, key=itemgetter(0, 1))
shijo += sorted(ac, key=itemgetter(1, 0))

#print(shijo)
minimum = -2 * pow(10, 9)
tempera = 0
for i, j, k in shijo:
  tempera += i
  if (tempera >= minimum):
    #print("Temp", tempera)
    minimum = tempera
  tempera += j

#print(shijo)
print(minimum)