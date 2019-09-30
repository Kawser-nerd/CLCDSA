n = int(input())
d = [int(input()) for i in range(n)]

max_kyori = sum(d)

max_d = max(d)
if max_kyori-max_d >= max_d:
  min_kyori = 0
else:
  min_kyori = max_d-(max_kyori-max_d)

print(max_kyori)
print(min_kyori)