s=input()
x,y=s[0],s[-1]
l=len(s)
if l%2==0:
  if x==y:
    print("First")
  else:
    print("Second")
  
if l%2==1:
  if x!=y:
    print("First")
  else:
    print("Second")