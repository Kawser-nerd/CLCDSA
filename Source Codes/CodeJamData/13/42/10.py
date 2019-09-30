def dul(n, p):
  p += 1
  ad = 2**(n-1)
  a = 0
  kor = 1
  su = 1
  while p > kor:
    a += ad
    ad >>= 1
    su <<= 1
    kor += su
  return a

#print [dul(3, i) for i in xrange(8)]


def should(n, p):
  if p == 2**n - 1:
      return p
  p += 1
  ad = 2**(n-1)
  a = 0
  kor = 0
  su = 1
  pkor = 0
  while p > a:
    a += ad
    ad >>= 1
    su <<= 1
    pkor = kor
    kor += su
  return pkor 

#print [should(3, i) for i in xrange(8)]



z = input()
for cas in xrange(1, z + 1):
    n, p = map(int, raw_input().strip().split())
    p -= 1
    print "Case #%d: %d %d" % (cas, should(n, p), dul(n, p))
