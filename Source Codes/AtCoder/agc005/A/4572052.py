S = input()

result = ""
for s in S:
  if(s == "T" and result == ""):
    result += s
  elif(s == "T" and result[-1] == "S"):
    result = result[:-1]
  else:
    result += s
print(len(result))