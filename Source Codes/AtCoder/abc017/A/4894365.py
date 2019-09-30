score=0
for i in range(3):
  s,e=map(int, input().split())
  score+=s*(e/10)
print(int(score))