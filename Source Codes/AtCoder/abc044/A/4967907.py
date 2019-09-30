n = int(input())
k = int(input())
x = int(input())
y = int(input())
sum = 0
for i in range(n):
  if i+1 <= k:
    sum += x
  else:
    sum += y
print(sum)