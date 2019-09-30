h, w = map(int, input().split())
s = [input() for _ in range(h)]

for i in range(h):
  for j in range(w):
    if s[i][j] == "#":
      if (i + 1 < h and s[i + 1][j] == "#") or (0 <= i - 1 and s[i - 1][j] == "#") or (j + 1 < w and s[i][j + 1] == "#") or (0 <= j - 1 and s[i][j - 1] == "#"):
        continue
      else:
        print("No")
        exit()
    else:
      continue
print("Yes")