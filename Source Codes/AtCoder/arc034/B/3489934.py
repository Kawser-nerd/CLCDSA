n = int(input())
a = []
for i in range(max(1,n-200),n):
  if i + sum([int(x) for x in list(str(i))]) == n:
    a.append(i)
print(len(a))
for x in a:
  print(x)