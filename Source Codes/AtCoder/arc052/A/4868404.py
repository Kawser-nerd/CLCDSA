s = input()
alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

for i in alph:
  s = s.replace(i,"")
print(s)