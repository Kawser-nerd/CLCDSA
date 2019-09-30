s=input()
S=[]
for i in range(len(s)):
  S.append(s[i])
print("yes" if len(set(S))==len(s) else "no")