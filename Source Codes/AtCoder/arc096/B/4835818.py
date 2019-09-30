n, c = map(int, input().split())
xv = []
for _ in range(n):
  xv.append(tuple(map(int, input().split())))

af = [0]
prevx = 0
for x, v in xv:
  af.append(af[-1] + v - x + prevx)
  prevx = x

bf = [0]
prevx = 0
for x, v in xv[::-1]:
  x = c - x
  bf.append(bf[-1] + v - x + prevx)
  prevx = x

maxa = [0]
for _af in af[1:]:
  maxa.append(max(maxa[-1], _af))
maxb = [0]
for _bf in bf[1:]:
  maxb.append(max(maxb[-1], _bf))

ans = 0
for i, _af in enumerate(af):
  if _af + maxb[n - i] - (xv[i - 1][0] if i != 0 else 0) > ans:
    ans = _af + maxb[n - i] - (xv[i - 1][0] if i != 0 else 0)
for i, _bf in enumerate(bf):
  if _bf + maxa[n - i] - (c - xv[n - i][0] if i != 0 else 0) > ans:
    ans = _bf + maxa[n - i] - (c - xv[n - i][0] if i != 0 else 0)
print(ans)