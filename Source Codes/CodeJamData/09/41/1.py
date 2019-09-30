def can(line, idx):
  return line[idx+1:].find('1') == -1

def main():
  T = int(raw_input())
  for t in range(1, T+1):
    print 'Case #%d:' % t,
    N = int(raw_input())
    A = []
    for i in range(N):
      A.append(raw_input())

    P = []
    U = [0] * N
    for i in range(N):
      for j in range(N):
        if not U[j] and can(A[i], j):
          P.append(j)
          U[j] = 1
          break

    result = 0
    for i in range(N):
      for j in range(i+1, N):
        result += P[i] > P[j]
    print result

if __name__ == '__main__':
  main()
