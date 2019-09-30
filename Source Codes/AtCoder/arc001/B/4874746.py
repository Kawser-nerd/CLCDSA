n = input().split(' ')
N = abs(int(n[0]) - int(n[1]))

cnt, mod = divmod(N, 10)
if mod > 7:
  cnt += 1
  mod = 10 - mod

cnt2, mod2 = divmod(mod, 5)
if mod2 > 3:
  cnt2 += 1
  mod2 = 5 - mod

print(cnt+cnt2+mod2)