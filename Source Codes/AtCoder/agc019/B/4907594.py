a = input().strip()

da = {}
for _a in a:
  if _a in da:
    da[_a] += 1
  else:
    da[_a] = 1

zc = 0
for v in da.values():
  if v >= 2:
    zc += (v * (v-1)) // 2


print((len(a) * (len(a) - 1)) // 2 - zc + 1)