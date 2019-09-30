a = int(input())
b = int(input())
c = int(input())

import fractions
x = a * b // fractions.gcd(a, b)

print(-(-c//x) * x)