L, R, G, U = None, None, None, None

def linked(A, B):
  return all([a < B[i] for i, a in enumerate(A)])

def match(n):
  global L, R, G, U
  if U[n]: return False
  U[n] = True
  for i in G[n]:
    if R[i] == -1 or match(R[i]):
      L[n], R[i] = i, n
      return True
  return False

def main():
  global L, R, G, U
  T = int(raw_input())
  for t in range(1, T+1):
    print 'Case #%d:' % t,
    N, K = map(int, raw_input().split())
    A = []
    for i in range(N):
      A.append(map(int, raw_input().split()))

    G = []
    for i in range(N):
      links = []
      for j in range(N):
        if linked(A[i], A[j]):
          links.append(j)
      G.append(links)

    L, R = [-1] * N, [-1] * N
    result = 0
    for i in range(N):
      if L[i] != -1: continue
      U = [0] * N
      result += match(i)
    print N - result


if __name__ == '__main__':
  main()
