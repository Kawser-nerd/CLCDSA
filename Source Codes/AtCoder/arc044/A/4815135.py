N = int(input())

def is_prime(n):
    for i in range(2, int(n **0.5) + 1):
        if n % i == 0:
            return False
    return n != 1
   
if N == 1:
    print('Not Prime')
elif is_prime(N):
    print('Prime')
elif N % 2 != 0 and N % 5 != 0 and N % 3 != 0:
        print('Prime')
else:
    print('Not Prime')