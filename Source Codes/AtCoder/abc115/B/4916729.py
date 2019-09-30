import sys

def main(inp):
    N = int(next(inp))
    P = sorted([int(next(inp)) for _ in range(N)],reverse=True)
    P[0]=int(P[0]/2)
    
    return sum(P)
  
print(main(sys.stdin))