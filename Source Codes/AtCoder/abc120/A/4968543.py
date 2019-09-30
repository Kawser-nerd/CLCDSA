import math

i = list(map(int, input().split()))
A = i[0]
B = i[1]
C = i[2]

if(A * C <= B):
  print(C)

if(A * C > B):
  if(B >= A):
    print(math.floor(B / A))
  else:
    print(0)