import sys
N = int(input())
b = list(map(int, input().split()))

ans = []
while len(b) > 0:
  for i in range(len(b)-1, -1, -1):
    if i+1 == b[i]:
      ans.append(b.pop(i))
      poped = True
      break
  else:
    print(-1)
    sys.exit()

for a in reversed(ans):
  print(a)