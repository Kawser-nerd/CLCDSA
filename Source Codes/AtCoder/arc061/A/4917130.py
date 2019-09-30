s = list(input())

ans = 0
for i in range(1 << len(s) - 1):
  ans += eval(s[0] + "".join(("+" if i >> j & 1 else "") + x for j, x in enumerate(s[1:])))
print(ans)