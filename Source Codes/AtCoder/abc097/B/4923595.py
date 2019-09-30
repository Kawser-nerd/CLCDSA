x = int(input())
y = []
for i in range(1,33):
  for j in range(2,11):
    if i**j <= x:
      y.append(i**j)
print(max(y))