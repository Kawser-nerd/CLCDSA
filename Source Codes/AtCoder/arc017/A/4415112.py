n = int(input())
q = int(n**0.5)
b = 1
for i in range(2, q+1):
  if n % i == 0:
    b = 0
    break
if b:
  print("YES")
else:
  print("NO")