A,B = [int(x) for x in input().split()]
if(B%A == 0):
  print(int(B/A))
else:
  print(int(B/A)+1)