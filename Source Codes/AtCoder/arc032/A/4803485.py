import sys
input = sys.stdin.readline

#n?????
def is_prime(n):
    if n == 1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

n = int(input())
if is_prime(n*(n+1)//2):
    print('WANWAN')
else:
    print('BOWWOW')