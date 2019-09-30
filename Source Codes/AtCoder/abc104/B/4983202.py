S = list(input())
ans = 0
for i in range(2,len(S)-1):
  if S[i] == "C":
    ans += 1
    S[i] = S[i].lower()
if S[0]=="A" and ans==1:
  S[0] = S[0].lower()
  s = ""
  for i in range(len(S)):
    s += S[i]
  if s.islower():
    print("AC")
  else:
    print("WA")
else:
  print("WA")