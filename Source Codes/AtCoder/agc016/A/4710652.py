s = list(input())
ans = 10**5
for i in set(list(s)):
  q = s[:]
  cnte = 0
  while len(set(q)) > 1:
    new = [""]*(len(q)-1)
    for j in range(len(q)-1):
      if q[j] == i or q[j+1] == i:
        new[j] = i
      else:
        new[j] = q[j]
    q = new
    cnte += 1
  if cnte < ans:
    ans = cnte
print(ans)