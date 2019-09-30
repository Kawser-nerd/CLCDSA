sd = input()
t = input()
lsd = len(sd)
lt = len(t)
for i in range(lsd-lt,-1,-1):
  for j in range(lt):
    if sd[i+j] != "?" and sd[i+j] != t[j]:
      break
  else:
      print((sd[:i]+t+sd[i+lt:]).replace("?","a"))
      break
else:
  print("UNRESTORABLE")