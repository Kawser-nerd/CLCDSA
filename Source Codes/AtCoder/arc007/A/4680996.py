x=input()
s=input()
l=[]
for i in range(len(s)):
  if s[i]!=x:
    l.append(s[i])
print(''.join(l))