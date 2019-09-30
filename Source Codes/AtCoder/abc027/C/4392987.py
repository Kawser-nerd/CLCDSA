import sys
inp = sys.stdin.readline

N = int(inp())

x, y = 1, 0
while True:
  if((len(str(bin(N)))-y)%2 == 1):
    x = 2*x + 1
  else:
    x = 2*x
  if(x > N):
    if(y == 1):
      print("Takahashi")
    else:
      print("Aoki")
    break
  y ^= 1