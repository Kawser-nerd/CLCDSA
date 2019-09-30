S = input()
t = 0
s = 0
for c in S:
  if c=="T" and s==0:
    t += 1
  elif c=="T":
    s -= 1
  else:
    s += 1
print(s+t)