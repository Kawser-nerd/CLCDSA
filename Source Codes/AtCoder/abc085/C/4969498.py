#ABC 085 C Otoshidama
N, Y = (int(i) for i in input().split())

def find():
  rhs = Y - 1000 * N

  for x in range(N+1):
    for y in range(N+1-x):
      if 9000 * x + 4000 * y == rhs:
        return x, y, N-x-y
      
  return -1, -1, -1

print(("{} {} {}").format(*find()))