N = int(input())
for x in range(26):
  for y in range(15):
    if (4 * x + 7 * y == N):
      print('Yes')
      exit()

print('No')