def is_prime(N):
    for i in range(2, N):
        if not(N%i):
            return 'NO'
    else:
        return 'YES'

print(is_prime(int(input())))