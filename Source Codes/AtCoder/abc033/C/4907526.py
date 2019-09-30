n = input()

cnt = 0
x = ""

for i in n:
  if i == "+":
    if "0" in x:
      x = ""
    else:
      x = ""
      cnt = cnt + 1
  else:
    x = x + i

if "0" not in x:
  cnt = cnt + 1

print(cnt)