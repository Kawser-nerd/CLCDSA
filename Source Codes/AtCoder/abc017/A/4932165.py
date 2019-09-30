point = 0
for i in range(0,3):
  s,e = map(int,input().split())
  point += s*e/10
print(int(point))