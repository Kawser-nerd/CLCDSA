a=list(map(int,input().split()))
if all([x in a for x in [4,6,9,11]]):
  s='Yes'
  print(s)
  exit()
if 2 in a:
  s='No'
elif sum([x in a for x in [4,6,9,11]])==1:
  s='No'
else:
  s='Yes'
print(s)