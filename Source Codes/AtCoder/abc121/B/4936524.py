N,M,C = map(int,input().split())
deep  = list(map(int,input().split()))
score = 0
for n in range(1,N+1):
  blue = list(map(int,input().split()))
  linear = 0
  for m in range(1,M+1):
    linear += deep[m-1] * blue[m-1]
  if linear + C > 0:
    score += 1
print(score)