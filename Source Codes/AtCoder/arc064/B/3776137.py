S = input()
if S[0] == S[-1]:
  if len(S)%2 == 0:
    print("First")
  else:
    print("Second")
else:
  if len(S)%2 == 1:
    print("First")
  else:
    print("Second")