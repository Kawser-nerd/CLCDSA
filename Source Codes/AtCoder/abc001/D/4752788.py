SE = []
for n in range(int(input())):
  s, e = map(int, input().split('-'))
  s = s - s % 5
  e = e + (5 - e) % 5
  e = e + 40 if e % 100 == 60 else e
  SE.append([s, e])
SE.sort()
ans = []

S, E = SE[0]
for s, e in SE:
  if E < s:
    ans.append((S, E))
    S, E = s, e
  else:
    E = max(E, e)
[print('{:0>4}-{:0>4}'.format(s,e)) for s, e in ans]
print('{:0>4}-{:0>4}'.format(S,E))