s = input()
p = 0

m = []
for x in s[::-1]:
  if x == '+':
    p += 1
  elif x == '-':
    p -= 1
  else:
    m.append(p)

m.sort()
for i in range(len(m)//2):
  m[i] *= -1
print(sum(m))