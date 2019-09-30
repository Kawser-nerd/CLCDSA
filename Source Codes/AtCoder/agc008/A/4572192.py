x, y = map(int,input().split())

if(0 <= x < y or x < y <= 0):
  print(abs(x-y))
elif(0 < y < x or y < x < 0):
  print(abs(x-y)+2)
else:
  print(abs(abs(x)-abs(y))+1)