from math import sqrt


def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


def main():
    n = int(input())
    s = n * (n + 1) // 2
    if is_prime(s):
        print("WANWAN")
    else:
        print("BOWWOW")


if __name__ == "__main__":
    main()