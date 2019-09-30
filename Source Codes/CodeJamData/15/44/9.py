# python 3.4 !!

from fractions import gcd

def lcm(a, b):
    return a * b // gcd(a, b)


MODULUS = 1000000007

num_trials = int(input())

#prev: 
# 0 = nothing
# 2 = row of 2s
# 3 = 2 rows of 3s
# -1 = 2-row snake, period 3
# -2 = 2-row snake, period 6
# -3 = 3-row snake, period 4


from functools import lru_cache
@lru_cache(maxsize = None)
def recurse(R, Cmod3, Cmod6, Cmod4, prev, period):
    if R < 0:
        return 0
    elif R == 0:
        return 1

    count = 0
    if prev != 3:
        count += recurse(R-2, Cmod3, Cmod6, Cmod4, 3, period)

    if prev != 2:
        c0 = recurse(R-1, Cmod3, Cmod6, Cmod4, 2, period)


        c1 = 0
        c2 = 0
        c3 = 0

        if Cmod3 == 0:
            c1 = gcd(period, 3) * recurse(R-2, Cmod3, Cmod6, Cmod4, 2, lcm(period, 3))
        if Cmod6 == 0:
            c2 = gcd(period, 6) * recurse(R-2, Cmod3, Cmod6, Cmod4, 2, lcm(period, 6))
        if Cmod4 == 0:
            c3 = gcd(period, 4) * recurse(R-3, Cmod3, Cmod6, Cmod4, 2, lcm(period, 4))

        count += c0 + c1 + c2 + c3

    return count % MODULUS


def compute():
    R, C = map(int, input().split())

    return recurse(R, C % 3, C % 6, C % 4, 0, 1)


for i in range (0, num_trials):
    print("Case #" + str(i+1) + ": " + str(compute()))

#print(recurse(7, 0, 0, 0, 0, 1))
