s=input();d=['Monday','Tuesday','Wednesday','Thursday','Friday'][::-1]
for i,e in enumerate(d):
  if e==s:
    print(i+1);exit()
else:
  print(0)