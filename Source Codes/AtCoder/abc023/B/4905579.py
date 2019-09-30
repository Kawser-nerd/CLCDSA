n = int(input())
s = input()

if n % 2 == 0:
  print(-1)
  exit()

D = {'b': 'c', 'c': 'a', 'a': 'b'}
t = ['b', 'a', 'c']
ans = n // 2
for c1, c2 in zip(s[:-1], s[1:]):
  if c1 not in D.keys():
    ans = -1
    break
  if D[c1] != c2:
    ans = -1
    break

if t[ans % 3] != s[0]:
  ans = -1
    
print(ans)