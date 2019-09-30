s = input()
L = []
for i in range(len(s)):
  if not s[i] in L:
    L.append(s[i])
ans = float('inf')
if len(L) == 1:
  print(0)
else:
  for i in range(len(L)):
    k = s
    sub = 0
    flag = False
    while flag == False:
      cur = ''
      cnt = 0
      for j in range(len(k)-2,-1,-1):
        if cnt == len(cur):
          if k[j] == L[i]:
            cur = L[i]*2 + cur
          else:
            cur = k[j] + cur
        else:
          if k[j] == L[i]:
            cur = L[i] + cur
          else:
            None
        cnt += 1
      check = L[i]*len(cur)
      sub += 1
      if check == cur:
        if sub <= ans:
          ans = sub
        flag = True
      else:
        k = cur
  print(ans)