s = str(input())
i = 0
ans = [] 

for let in s:
  if let == "A" or let == "T" or let == "G" or let == "C":
    i += 1
  else:
    ans.append(i)
    i = 0
ans.append(i)    
print(max(ans))