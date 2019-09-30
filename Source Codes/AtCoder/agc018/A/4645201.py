from functools import reduce
import fractions
# import math


def gcd_lst(lst):
    return reduce(fractions.gcd, lst)
    # return reduce(math.gcd, lst)

    
N, K = map(int, input().split())
lst_A = list(map(int, input().split()))
max_A = max(lst_A)
gcd_A = gcd_lst(lst_A)

ans = "IMPOSSIBLE"
if K%gcd_A==0 and K<=max_A:
    ans = "POSSIBLE"

print(ans)