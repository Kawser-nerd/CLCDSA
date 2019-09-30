S = input()
flag = 1
if S.count("W") == 0 and S.count("E") == 0:
  if S.count("N") == 0 or S.count("S") == 0:
    flag = 0
  else:
    flag = 1
elif S.count("W") == 0 or S.count("E") == 0:
  flag = 0
elif S.count("N") == 0 and S.count("S") == 0:
  flag = 1
elif S.count("N") == 0 or S.count("S") == 0:
  flag = 0
else:
  flag = 1
if flag == 1:
  print("Yes")
else:
  print("No")