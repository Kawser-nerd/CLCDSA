s = input()
m = "gp"*(len(s)//2+1)
g = 0
for i in range(len(s)):
  if s[i] == m[i]:
    continue
  elif s[i] == "p":
    g -= 1
  else:
    g += 1
print(g)