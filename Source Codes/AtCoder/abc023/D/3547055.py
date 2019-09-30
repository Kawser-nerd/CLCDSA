import sys
n = int(input())
a = [list(map(int,sys.stdin.readline().split())) for _ in  range(n)]
syo = 0
dai = 10**15
def cheak(x):
  tmp = []
  for i in range(n):
    if x - a[i][0] < 0:
      return 0
    ka = (x - a[i][0])//a[i][1]
    tmp.append(ka)
  tmp.sort()
  for i in range(n):
    if i>tmp[i]:
      return 0
  return 1
while True:
  if dai-syo <= 1:
    if cheak(dai) != 1:
          dai = syo
    break
  kon = (dai+syo)//2
  c = cheak(kon)
  if c == 1:
    dai = kon
  else:
    syo = kon
print(dai)