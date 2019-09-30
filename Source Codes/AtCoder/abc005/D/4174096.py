import sys

def rectangles(D, N):
  """Make list of total delicious point for all rectangles in D"""
  t = [[0] * (N+1) for _ in range(N+1)]
  for i in range(N)[::-1]:
    for j in range(N)[::-1]:
      t[i][j] = D[i][j] + t[i+1][j] + t[i][j+1] - t[i+1][j+1]
  return t


def list_maxpoint(N, rect):
  """Make list of max delicious point for all num."""
  m = [0] * (N * N + 1)
  for i in range(N):
    for j in range(N):
      for ie in range(i+1, N+1):
        for je in range(j+1, N+1):
          n = (ie - i) * (je - j)
          m[n] = max(m[n], rect[i][j] - rect[i][je] - rect[ie][j] + rect[ie][je])
  return m


def main():
  input = sys.stdin.readline
  N = int(input())
  D = [list(map(int, input().split())) for _ in range(N)]
  Q = int(input())
  P = [int(input()) for _ in range(Q)]
  
  rect = rectangles(D, N)
  lmax = list_maxpoint(N, rect)
  for p in P:
    print(max(lmax[:(p+1)]))

if __name__ == '__main__':
  main()