H, W, N = map(int, input().split())
L = [list(map(int, input().split())) for i in range(N)]
dic = {}
for l in L:
  try:
    dic[l[0]].append(l[1])
  except:
    dic[l[0]] = [l[1]]
def get(H, N):
  if N == 0:
    return H
  area = 1.
  for i in range(1, H):
    try:
      for block in sorted(dic[i+1]):
        if 1 <= block and block <= area:
          return i
      if not area+1 in dic[i+1]:
        area += 1
    except:
      area = area+1
  return H
print(get(H, N))