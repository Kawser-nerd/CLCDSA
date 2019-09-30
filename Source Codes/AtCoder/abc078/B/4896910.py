x, width, space = map(int, input().split())
N = 0
if x < width+space:
  print("0")
else:
    total_space = width + (space)
    N = (x- space) // total_space
print(N)