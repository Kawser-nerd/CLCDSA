n = int(input())
alist = list(sorted(map(int, input().split())))
maxa = alist[-1]
halfa = maxa / 2
mina = maxa
a2 = 0
for a in alist:
  if abs(halfa - a2) > abs(halfa - a):
    a2 = a
print(maxa, a2)