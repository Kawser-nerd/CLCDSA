N = int(input())
ans = 0
for i in range(N):
    ans += i + 1
    
def is_prime(n):
    for i in range(2, int(n **0.5) + 1):
        if n % i == 0:
            return False
    return n != 1
    
print('WANWAN' if is_prime(ans) else 'BOWWOW')