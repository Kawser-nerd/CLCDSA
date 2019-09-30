a, b = list(map(int, input().split()))
g1 = [["#" for i in range(100)] for i in range(20)]
g2 = [["." for i in range(100)] for i in range(20)]

a, b = a-1, b-1
j = 0
while a!=0:
  for i in range(0, 100, 2):
    g1[j][i] = "."
    a -= 1
    if a==0:
      break
  j += 2

j = 1
while b!=0:
  for i in range(0, 100, 2):
    g2[j][i] = "#"
    b -= 1
    if b==0:
      break
  j += 2

g1.extend(g2)
print(40, 100)
for ele in g1:
  print("".join(ele))