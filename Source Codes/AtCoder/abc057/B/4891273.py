N, M = map(int, input().split())
students = [tuple(map(int,input().split())) for i in range(N)]
cps = [tuple(map(int,input().split())) for i in range(M)]

def manlen(a,b) :
  return abs(a[0]-b[0])+abs(a[1]-b[1])

for std in students:
  lengths = [manlen(std,cp) for cp in cps]
  bestcp = 1 + lengths.index(min(lengths))
  print(bestcp)