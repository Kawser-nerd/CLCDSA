S,T = input(),input()
l = "a t c o d e r"
list_ = l.split()
flag = 0
for i in range(0,len(S)):
 if S[i] == T[i]:
  flag += 1
 else:
  if (S[i] == "@" or T[i] == "@") and (S[i] in list_ or T[i] in list_): 
   flag += 1
if flag == len(S):
 print("You can win")
else:
 print("You will lose")