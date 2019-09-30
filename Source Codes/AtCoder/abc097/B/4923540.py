x = int(input())
y = []
for i in range(1,33):
  for j in range(2,11):
    y.append(i**j)
    
ans = 1
for i in y:
  if i <= x:
    ans = max(ans, i)
print(ans)