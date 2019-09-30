n = int(input())
row = 0
for i in range(100):
  if 2 ** i <= n <= 2 ** (i + 1) - 1:
    row = i
    break
    
def seki(k, n):
  for _ in range(n):
    k = 4 * k + 2
  return k

k = 0
if row % 2 != 0:
  k = 2
  cri = seki(k, row // 2)
  if n < cri:
    print("Aoki")
  else:
    print("Takahashi")
else:
  k = 1
  cri = seki(k, row // 2)
  if n < cri:
    print("Takahashi")
  else:
    print("Aoki")