MOD = 10009

def eval(phrase, P, W):
  result = 0
  for term in P:
    value = 1
    for pos in term:
      freq = 0
      for w in phrase:
        freq += W[w][pos]
      value = (value * freq) % MOD
    result += value
  return result % MOD

def main():
  import sys
  from itertools import product
  T = int(raw_input())
  print T
  for t in range(1, T+1):
    P, K = raw_input().split()
    K = int(K)
    N = int(raw_input())
    W = []
    print >>sys.stderr, '#', t, N, K
    for i in range(N):
      word = raw_input()
      freq = [0] * 26
      for ch in word:
        freq[ord(ch)-ord('a')] += 1
      W.append(freq)
    P = P.split('+')
    for i, p in enumerate(P):
      P[i] = [ord(ch)-ord('a') for ch in p]
    print N
    for w in W:
      print ' '.join([str(ch) for ch in w])
    print len(P)
    for p in P:
      print len(p),
      print ' '.join([str(ch) for ch in p])
    print K


if __name__ == '__main__':
  main()
