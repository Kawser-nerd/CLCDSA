S = list(input())

D = list("abcdefghijklmnopqrstuvwxyz")

if len(S) == 26:
  cnt = 0
  L = []
  for i in range(25, -1, -1):
    Flag = True
    for j in range(cnt, 26):
      if S[i] == D[j]:
        L.append(S[i])
        cnt = j
        Flag = False
        break
    if Flag:
      L.sort()
      for k in L:
        if k > S[i]:
          S[i] = k
          break
      print("".join(S[:i + 1]))
      exit()
  print("-1")      
else:
  for i in S:
    D.remove(i)
  print("".join(S) + D[0])