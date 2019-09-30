k = int(input())
a,b = 1,1
for _ in [0]*k:
  a,b = a+b,a
print(a,b)