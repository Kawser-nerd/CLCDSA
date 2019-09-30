import sys
N = int(input())
b = list(map(int, input().split()))

ans = []
while len(b) > 0:
  #print(b)
  poped = False
  for i in range(len(b)-1, -1, -1):
    #print(i+1, b[i])
    if i+1 == b[i]:
      ans.append(b.pop(i))
      poped = True
      break
  if not poped:
    print(-1)
    sys.exit()

ans.reverse()
for a in ans:
  print(a)