def main():
    n = int(input())

    if judge(n):
        print('Prime')
    else:
        print('Not Prime')

def judge(n):
    if is_prime(n):
        return True

    if n == 1:
        return False
    
    if n % 2 == 0:
        return False
    
    if n % 10 == 5:
        return False
    
    if n % 3 == 0:
        return False
    
    return True


def is_prime(n):
    if n == 1:
        return False

    if n != 2 and n % 2 == 0:
        return False

    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    
    return True

main()