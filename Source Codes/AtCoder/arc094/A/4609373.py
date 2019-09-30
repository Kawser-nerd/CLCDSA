tin = [int(i) for i in input().split(' ') ]
A,B,C = tin[0],tin[1],tin[2]
if (A+B+C - max(A,B,C)) % 2 == 0:
  print(int((3*max(A,B,C) - A - B - C)/2))
else:
  print( int( (3*max(A,B,C) - A - B - C - 1)/2 + 2 ) )