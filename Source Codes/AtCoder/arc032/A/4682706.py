import math
def is_prime(n):
    if n == 1:
        w = False
    else:
        n2 = int(math.sqrt(n)) + 1
        w = True
        for i in range(2,n2):
            if n % i == 0:
                w = False
                break
    return w
n = int(input())
if is_prime(n*(n+1)/2):print('WANWAN')
else:print('BOWWOW')