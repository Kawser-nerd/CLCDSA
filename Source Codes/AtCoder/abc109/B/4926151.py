import sys
 
n = int(input())
l = []
 
for i in range(n):
  s = input()
  if(i == 0):
    l.append(s)
    continue
  if(s in l or s[0] != l[i-1][-1]):
    print("No")
    sys.exit()
  l.append(s)
 
print("Yes")