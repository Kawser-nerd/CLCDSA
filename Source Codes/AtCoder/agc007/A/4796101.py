H, W = map(int, input().split())
dist = 0
for i in range(H):
  dist += input().count("#")
if dist == H+W-1:
  print("Possible")
else:
  print("Impossible")