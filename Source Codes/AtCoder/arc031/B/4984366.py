import copy
a = [list(input()) for _ in range(10)]

def search(a, x, y):
  for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
    if 0 <= x + dx < 10 and 0 <= y + dy < 10:
      if a[y + dy][x + dx] == "o":
        a[y + dy][x + dx] = "x"
        search(a, x + dx, y + dy)
        
def land(a, x, y):
  search(a, x, y)
  return all(all(i == "x" for i in l) for l in a)
  
def rec():
  for y in range(10):
    for x in range(10):
      if a[y][x] == "x":
        aa = copy.deepcopy(a)
        if land(aa, x, y):
          return True
          break

print("YES" if rec() else "NO")