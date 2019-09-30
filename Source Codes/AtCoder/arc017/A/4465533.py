def is_prime(n):
    
    # 2??????????????????
    if n % 2 == 0 and n != 2:
        return False

    # ?????????????
    for divisor in range(2, n//2):
        if n % divisor == 0:
            return False

    return True

if __name__ == "__main__":
    N = int(input())
    print('YES' if is_prime(N) else 'NO')