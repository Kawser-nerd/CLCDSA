import itertools
n = int(input())

counter = {}
for i in range(n):
  head = input()[0]
  if head not in counter:
    counter[head] = 1
  else:
    counter[head] += 1

char_num = 0
char_count = []
for c in "MARCH":
  if c in counter:
    char_num += 1
    char_count.append(counter[c])

ans = 0
if char_num < 3:
  print(0)
else:
  for a, b, c in itertools.combinations(char_count, 3):
    ans += a * b * c
  print(ans)