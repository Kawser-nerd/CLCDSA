n = int(input())

def is_prime(n):
    for i in range(2, n + 1):
        if i * i > n:
            break
        if n % i == 0:
            return False
    return n != 1

res = 0
for i in range(n+1):
    res += i
    
if is_prime(res):
    print('WANWAN')
else:
    print('BOWWOW')