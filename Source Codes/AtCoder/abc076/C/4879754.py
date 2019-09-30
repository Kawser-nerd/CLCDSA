S2 = input()
T = input()
N = len(S2)

Tplace = {i:False for i in range(N)}
#print(Tplace)

for i in range(N-len(T)+1):
  counter = 0
  for j in range(len(T)):
    if S2[i+j] == T[j] or S2[i+j] == "?":     
      counter += 1
#      print(S2[i+j],T[j],counter)
      continue
    else:
#      print(2,i,j,S2[i+j])
      break
#  print(3)
  if counter == len(T):
    Tplace[i] = True
#print(Tplace)

ans = []

for key, value in Tplace.items():
  if value:
    tmp = S2[:key] + T + S2[key+len(T):] 
    tmp2 = tmp.replace('?', 'a')
    ans.append(tmp2)
ans.sort()
print(ans[0] if len(ans) > 0 else "UNRESTORABLE")