def ans():
  S = input()
  res = ""
  for s in S:
    if(s == "O" or s == "D"):
      res += "0"
    elif(s == "I"):
      res += "1"
    elif(s == "Z"):
      res += "2"
    elif(s == "S"):
      res += "5"
    elif(s == "B"):
      res += "8"
    else:
      res += s
  print(res)
ans()