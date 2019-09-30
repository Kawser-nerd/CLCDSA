N = int(input())
L = list(input().split())
K = []
wordlist = [['z','r'],['b','c'],['d','w'],['t','j'],['f','q'],['l','v'],['s','x'],['p','m'],['h','k'],['n','g']]
for i in range(N):
  cur = ''
  L[i] = L[i].lower()
  for j in range(len(L[i])):
    for k in range(10):
      if L[i][j] in wordlist[k]:
        cur += str(k)
        break
  if cur != '':
    K.append(cur)
ans = ''
if len(K) != 0:
  for i in range(len(K)-1):
    ans += K[i]+' '
  ans += K[len(K)-1]
  print(ans)
else:
  print()