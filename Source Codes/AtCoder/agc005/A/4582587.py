x = []
s = input()
for i in s:
  if i == "T" and x != [] and x[-1] == "S":
    x.pop()
  else:
    x.append(i)
print(len(x))