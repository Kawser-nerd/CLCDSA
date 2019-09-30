import sys

s = input()
K = int(input())

chars = sorted(set(s))
n = len(s)

for j in range(min(3, len(chars))):
  ans = chars[j]
  K -= 1
  if K == 0:
    print(ans)
    break
  while True:
    places = []
    index = -1
    while True:
      index = s.find(ans, index+1)
      if index == -1:
        break
      places.append(index)
      
    if len(ans) == len(s) - places[0]:
      break

    next_char = 'z' * 6
    for k in places:
      if k >= len(s)-len(ans):
        break
      next_char = min(next_char, s[k+len(ans)])

    ans += next_char
    K -= 1
    if K == 0:
      print(ans)
      sys.exit()