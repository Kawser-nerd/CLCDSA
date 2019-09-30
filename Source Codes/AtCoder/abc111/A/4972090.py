S = input()
res = ""
for i in S:
  if i == "9":
    res += "1"
  elif i == "1":
    res += "9"
  else:
    res += i
print(res)