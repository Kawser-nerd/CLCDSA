import fractions
a,b=list(map(int, input().split()))
x = a//(fractions.gcd(a,b))
y = b//(fractions.gcd(a,b))
print("{0}:{1}".format(x,y))