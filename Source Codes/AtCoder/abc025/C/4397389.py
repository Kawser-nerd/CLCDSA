b = [list(map(int,input().split())) for _ in range(2)]
c = [list(map(int,input().split())) for _ in range(3)]

reach = [None] * (1<<18)
def ox(x = 0, y = 0):
  if(y == 9):
    point = 0
    for i in range(3):
      for j in range(2):
        if(((x >> (i*3+j)*2)&3) ^ ((x >> (i*3+j+1)*2)&3)):
          point += 0
        else:
          point += c[i][j]
    for i in range(3):
      for j in range(2):
        if(((x >> (j*3+i)*2)&3) ^ ((x >> ((j+1)*3+i)*2)&3)):
          point += 0
        else:
          point += b[j][i]
    return point
  else:
    y += 1
    result = []
    for i in range(9):
      j = 1 << i * 2
      if(((x >> (i*2)) & 3) == 0):
        if(y%2 == 0):
          t = x|j
        else:
          t = x|j*2
        if(reach[t] is None):
          reach[t] = ox(t, y)
        result.append(reach[t])
    if(y%2 == 1):
      return max(result)
    else:
      return min(result)

naohiro = ox()
naoko = sum(b[0] + b[1] + c[0] + c[1] + c[2]) - naohiro
print(naohiro)
print(naoko)