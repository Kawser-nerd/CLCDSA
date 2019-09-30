a = 0
for i in range(3):
  ls = [int(j) for j in input().split()]
  a += int(ls[0] * ls[1] / 10)
print(a)