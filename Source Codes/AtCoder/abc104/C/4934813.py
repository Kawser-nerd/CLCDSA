D, G = map(int,input().split())
p,c = {},{}
for i in range(1,D+1):
  pi,ci = map(int,input().split())
  p[i] = pi
  c[i] = ci
ans = sum(p.values())

for i in range(2**D):
  cmp = {i:False for i in range(1,D+1)}
  score = 0
  ans_tmp = 0
  for j in range(D):
    if (i >> j) & 1:
      cmp[j+1] = True
      score += (j+1)*100*p[j+1]+c[j+1]
      ans_tmp += p[j+1]
  keys = [k for k,v in cmp.items() if v == False]
  if G > score and len(keys) > 0:
    if (G-score) // (max(keys)*100) <= p[max(keys)]:
      ans_tmp += (G-score) // (max(keys)*100)
      if (G-score) % (max(keys)*100) != 0:
        ans_tmp += 1 
    else:
      ans_tmp = sum(p.values())
  ans = min(ans, ans_tmp)
        
print(ans)