s=input()
if len(s)==2:
  if s[0]==s[1]:
    print(1,2)
  else:
    print(-1,-1)
  exit(0)
for i, (a,b,c) in enumerate(zip(s,s[1::],s[2::]),1):
  if a==b:
    print(i,i+1)
    exit(0)
  if a==c:
    print(i,i+2)
    exit(0)
print(-1,-1)