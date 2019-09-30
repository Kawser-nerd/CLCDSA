S = input()
if S[0] == "A" and S[2:-1].count("C") == 1 and S.count("A") == 1 and S.count("C") == 1:
  S=S.replace("A","a")
  S=S.replace("C","c")
  if S.islower():
    print("AC")
  else:
    print("WA")
else:
  print("WA")