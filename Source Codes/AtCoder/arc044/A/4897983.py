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
    if (
        is_prime(n)
        or n >= 2
        and n % 2 != 0
        and n % 10 != 5
        and sum(int(c) for c in str(n)) % 3 != 0
    ):
        print("Prime")
    else:
        print("Not Prime")


if __name__ == "__main__":
    main()