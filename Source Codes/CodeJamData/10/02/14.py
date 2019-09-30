
import sys

def GCD(x, y):
# The greatest common denominator (GCD) is the largest positive integer
# that divides into both numbers without a remainder.
# Examples: GCD(256,64)=64, GCD(12,8)=4, GCD(5,3)=1

 # Work With absolute values (positive integers)
 if x < 0 : x = -x
 if y < 0 : y = -y

 if x + y > 0 :
  g = y
  # Iterate Until x = 0
  while x > 0:
   g = x
   x = y % x
   y = g
  return g
 else:
  # Error, both parameters zero
  return 0

def f(a) :
    xx = a[-1]
    x = xx
    a = a[:-1]
    for i in range(len(a)) :
	a[i] = a[i]-x
    g = a[0]
    for x in a[1:] :
	g = GCD(g,x)
    g = abs(g)
    return (g-xx)%g

c = int(sys.stdin.readline())
for i in range(1,c+1) :
    a = map(int,sys.stdin.readline().split())
    n = a[0]
    a = a[1:]
    assert len(a)==n
    print "Case #%d: %s" % ( i, f(a) )

