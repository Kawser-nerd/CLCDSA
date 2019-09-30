a, b, c, k = map(int, input().split())
s, t = map(int, input().split())
if s+t<k:
  ans = a*s + b*t
else:
  ans = a*s + b*t - (s+t)*c
print(ans)