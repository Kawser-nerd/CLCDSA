s=input()
t=input()
count=0
for i in range(len(s)):
  if s!=t:
    count+=1
    s=s[-1]+s[:-1]
  else:
    break
print("No" if count==len(s) else "Yes")