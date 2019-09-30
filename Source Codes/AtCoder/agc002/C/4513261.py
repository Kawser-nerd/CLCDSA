n,l = map(int, input().split())
a = list(map(int, input().split()))
MAX = 0
MAX_i = 0
for i in range(n-1):
  now = a[i] + a[i+1]
  if now > MAX:
    MAX = now
    MAX_i = i
if MAX >= l:
  print("Possible")
  for i in range(MAX_i):
    print(i+1)
  for i in range(n-MAX_i-1):
    print(n-i-1)
else:
  print("Impossible")