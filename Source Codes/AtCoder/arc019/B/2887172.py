import numpy as np


def is_palindrome():
    return A == A[::-1]


def main():
    l = len(A)
    if l == 1:
        print(0)
        return

    if is_palindrome():
        if l % 2 == 0:
            print(l * 25)
            return
        else:
            print((l - 1) * 25)
            return

    a_l = A[:l//2]
    a_r = A[l - l//2:][::-1]

    a_l2 = np.array(list(a_l))
    a_r2 = np.array(list(a_r))

    d_num = (a_l2 != a_r2).sum()

    if d_num == 1:
        print((l - 2) * 25 + 2 * 24)
        return

    print(l * 25)

if __name__ == '__main__':
    A = input()
    main()