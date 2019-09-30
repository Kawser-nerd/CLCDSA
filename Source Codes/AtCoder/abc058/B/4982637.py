o = list(input())
e = list(input())

ans = []
for i in range(len(o)):
  ans.append(o[i])
  if i < len(o)-1:
    ans.append(e[i])
  else:
    if len(e) == len(o):
      ans.append(e[i])
    
print("".join(ans))