s = input() 
k = -1
l = -1
flag = False
for i in range(0,len(s)-1):
  if s[i] == s[i+1]:
    flag = True
    k = i+1
    l = i+2
    break
if not flag:
  if len(s) > 2:
    for j in range(0,len(s)-2):
      if s[j] == s[j+2]:
        flag = True
        k = j+1
        l = j+3
        break
  else:
    None
print(k,l)