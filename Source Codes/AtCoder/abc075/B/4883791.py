h, w = map(int, input().split())
s = [input() for _ in range(h)]

for i in range(h):
  l = ""
  for j in range(w):
    if s[i][j] == "#":
      l += "#"
    else:
      x = 0
      for dh in [-1, 0, 1]:
        for dw in [-1, 0, 1]:
          if 0 <= i + dh < h and 0 <= j + dw < w and s[i + dh][j + dw] == "#":
            x += 1
      l += str(x)
  print(l)