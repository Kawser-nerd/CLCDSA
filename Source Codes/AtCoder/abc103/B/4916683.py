S = input()
T = input()
for i in range(len(S)):
  if S == T:
    break
  S = S[-1] + S 
  S = S[:-1]
if S == T:
  print("Yes")
else:
  print("No")