def matmul(a,b):
  c = a*b
  return c

a,b=map(int, input().split())
c = matmul(a,b)
if c%2==0:
  print("Even")
else:
  print("Odd")