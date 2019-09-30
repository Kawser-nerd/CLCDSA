def is_prime(n):
    i = 2
    while i * i <=n:
        if n % i == 0:
            return False
        i += 1
    return True
print('YES') if is_prime(int(input())) else print('NO')