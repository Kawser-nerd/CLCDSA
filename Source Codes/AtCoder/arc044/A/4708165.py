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
N = int(input())
if N==1:
    print('Not Prime')
else:
    if is_prime(N):
        print('Prime')
    else:
        n_last = N % 10
        s = list(str(N))
        wa = sum([int(c) for c in s])
        if (n_last %2 != 0) and (n_last%5 != 0) and (wa%3 != 0):
            print('Prime')
        else:
            print('Not Prime')