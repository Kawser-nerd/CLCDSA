n, t = map(int, input().split())
alist = list(map(int, input().split()))
minal = [alist[0]]
maxal = [alist[-1]]
for a in alist[1:]:
  if minal[-1] > a:
    minal.append(a)
  else:
    minal.append(minal[-1])

for a in alist[::-1][1:]:
  if maxal[-1] < a:
    maxal.append(a)
  else:
    maxal.append(maxal[-1])
maxal = maxal[::-1]

maxda = 0
ans = 0
prevmina, prevmaxa = None, None
for mina, maxa in zip(minal, maxal):
  if prevmina == mina and prevmaxa == maxa:
    continue
  elif maxa - mina == maxda:
    ans += 1
  elif maxa - mina > maxda:
    maxda = maxa - mina
    ans = 1
  prevmina, prevmaxa = mina, maxa

print(ans)