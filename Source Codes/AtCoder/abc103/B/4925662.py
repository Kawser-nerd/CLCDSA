S = input()
T = input()
N = ""
flg = False
for i in range(len(S)):
    N = S[i:]+S[:i]
    if N == T:
        flg = True
if flg:
  print("Yes")
else:
  print("No")