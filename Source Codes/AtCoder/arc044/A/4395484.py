N = int(input())
res = 'Prime'

def is_prime(n):
    for i in range(2, n + 1):
        if i * i > n:
            break
        if n % i == 0:
            return False
    return n != 1

if is_prime(N):
    res = 'Prime'
else:  
    
    if N == 1:
        res = 'Not Prime'
        
    if int(str(N)[-1]) == 5:
        res = 'Not Prime'

    if N%2 == 0:
        res = 'Not Prime'

    N = str(N)
    count = 0
    for i in range(len(N)):
        count += int(N[i])

    if count%3 == 0:
        res = 'Not Prime'
    
print(res)