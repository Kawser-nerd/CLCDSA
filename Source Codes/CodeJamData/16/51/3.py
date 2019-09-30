r = raw_input

def solve():
  s = r()
  stk = []
  ans = 0
  for ch in s:
    if len(stk) > 0 and ch == stk[-1]:
      stk.pop()
      ans += 10
    else:
      stk.append(ch)
  ans += 5 * len(stk) / 2
  return ans

T = int(r())
for t in range(1, T+1):
  ans = solve()
  print 'Case #%d: %d' % (t, ans)
