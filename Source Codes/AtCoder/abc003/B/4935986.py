a,b,c,d=input(),input(),"","";e=("a","t","c","o","d","e","r")
for i in range(len(a)):
  if a[i]!=b[i]:
    if a[i]=="@":
      if not b[i]in e:print("You will lose");exit()
    elif b[i]=="@":
      if not a[i]in e:print("You will lose");exit()
    else:print("You will lose");exit()
print("You can win")