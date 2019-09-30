ord_a = ord('a')
L = 26

S = list(map(lambda c: ord(c)-ord_a,input()))


memo = []

f = [0]*L
cnt = 0


for i,s in zip(reversed(range(len(S))),reversed(S)):

  cnt += (f[s] == 0)
  f[s] += 1
  if cnt == L:
    memo.append((i,f))
    f = [0]*L
    cnt = 0


result = [f.index(0)]

for i,f in reversed(memo):
  c = result[-1]
  for j in range(i,len(S)):
    s = S[j]
    f[s] -= 1
    if s == c:
      break

  result.append(f.index(0))

print(''.join(map(lambda x: chr(x+ord_a), result)))