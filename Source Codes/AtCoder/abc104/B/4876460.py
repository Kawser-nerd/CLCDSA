s = input()
if s[0] == "A":
  if s[2:-1].count("C") == 1:
    if s[1].islower() and s[-1].islower():
      s = s.replace("C","c").replace("A","a")
      if s.islower():
        print("AC")
        exit()

print("WA")