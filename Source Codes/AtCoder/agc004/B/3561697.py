n,x = map(int,input().split())
a = list(map(int,input().split()))
MIN = sum(a)
ans = MIN+0
tori = a + [0]
tori.pop()
for i in range(1,n):
  for j in range(n):
    ido = i+j
    if ido >= n:
      ido-=n
    if tori[j] > a[ido]:
      ans -= (tori[j] - a[ido])
      tori[j] = a[ido]
  MIN = min(ans + i*x,MIN)
print(MIN)