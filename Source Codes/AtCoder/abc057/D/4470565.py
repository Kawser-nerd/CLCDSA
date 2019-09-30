n, a ,b = map(int, input().split())
v = list(map(int, input().split()))
d = {}
for i in range(n):
  d.setdefault(v[i], 0)
  d[v[i]] += 1
c = sorted(list(set(v)), reverse=True)
c.append(0)
d[0] = 0
fact = [1 for _ in range(n+1)]
for i in range(n):
  fact[i+1] = fact[i] * (i+1)
ave = 0
cnt = 0
for i in range(a, b+1):
  t = i; cur = 0; sum=0
  while(cur<len(c)-1 and d[c[cur]]<=t):
    sum += c[cur] * d[c[cur]]
    t -= d[c[cur]]
    cur += 1
  sum += c[cur] * t
  if ave < (sum / i):
    ave = sum / i
    cnt = fact[d[c[cur]]] // fact[t] // fact[d[c[cur]]-t]
  elif ave == (sum / i):
    cnt += fact[d[c[cur]]] // fact[t] // fact[d[c[cur]]-t]
print(ave)
print(cnt)