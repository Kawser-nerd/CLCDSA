s=input()
for i in range(2**3):
  b=bin(i)[2:].zfill(3)
  a=s[0]
  for i in range(3):a+=("+"if b[i]=="0"else"-")+s[i+1]
  if eval(a)==7:print(a+"=7");exit()