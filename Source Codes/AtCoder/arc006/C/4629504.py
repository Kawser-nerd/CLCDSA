n = int(input())
w = []
for _ in range(n):
  w.append(int(input()))
  
m = []

while w:
  tmp = w.pop()
#  print("tmp = ", tmp)
  for i in range(len(m)):
#    print("i =", i, "m[i] =", m[i])
    if tmp >= m[i]:
      m[i] = tmp
      break
  else:
    m.append(tmp)
    
print(len(m))