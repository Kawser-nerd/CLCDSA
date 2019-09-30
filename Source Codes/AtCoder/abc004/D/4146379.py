import sys

def movecount(G, l):
  R = abs(G + l - 1)
  L = abs(l)
  if l > 0:
    return (R+1)*R//2 - (L-1)*L//2
  elif G >= L:
    return (R+1)*R//2 + (L+1)*L//2
  else:
    return (L+1)*L//2 - (R-1)*R//2


def main():
  input = sys.stdin.readline
  R, G, B = map(int, input().split())
  R, B = max(R, B), min(R, B)
  if (((R-1)//2 + (G-1)//2) <= 100):
    RL = -(R//2)
    GL = -(G-1)//2
    BL = -(B-1)//2
    ans = movecount(R,RL) + movecount(G, GL)+ movecount(B, BL)
  else:
    Lmin = -R - 100
    ans = 10**9
    for i in range(-1000, 1000):
      RL = i + 100
      GL = i + R
      BL = max((GL+G)-100, -(B-1)//2)
      comp = movecount(R,RL) + movecount(G, GL)+ movecount(B, BL)
      ans = min(ans, comp)
  print(ans)


if __name__ == '__main__':
  main()