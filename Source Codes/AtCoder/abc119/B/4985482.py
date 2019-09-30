a = 0
for i in range(int(input())):
  v,u = input().split()
  if u == "JPY":
    a += int(v)
  else:
    a += float(v)*380000
print(a)