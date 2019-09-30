N,L,T = map(int, input().rstrip().split())

ants = []
number_one_index = 0
for _ in range(N):
  x,w = map(int, input().rstrip().split())
  ants.append(int((x + (3-w*2)*T)%L))
  number_one_index += (x + (3-w*2)*T)//L

ants.sort()
number_one_index %= N
ants = ants[number_one_index:] + ants[:number_one_index]
for x in ants:
  print(x)