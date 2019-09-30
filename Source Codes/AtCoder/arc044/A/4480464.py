import math

N = int(input())

def is_prime(x):
    if x < 2: return False # 2????????
    if x == 2 or x == 3 or x == 5: return True # 2,3,5???
    if x % 2 == 0 or x % 3 == 0 or x % 5 == 0: return False # 2,3,5???????

    prime = 7
    step = 4
    while prime <= math.sqrt(x):
        if x % prime == 0: return False

        prime += step
        step = 6 - step

    return True

ans = 'Not Prime'
if is_prime(N):
    ans = 'Prime'
else:
    if N != 1 and N % 2 != 0 and N % 10 != 5 and N % 3 != 0:
        ans = 'Prime'

print(ans)