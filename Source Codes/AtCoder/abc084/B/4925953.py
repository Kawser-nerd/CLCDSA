import sys

n, m = list(map(int, input().split()))
s = input()

if(s[n] != "-"):
  print("No")
  sys.exit()

for i in range(n):
  if(s[i] != "-"):
    continue
  else :
    print("No")
    sys.exit()

for i in range(m):
  if(s[i+n+1] != "-"):
    continue
  else :
    print("No")
    sys.exit()

print("Yes")