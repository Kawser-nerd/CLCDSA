def main():
    A, B = map(int, input().split())
    S = input()
    print('YNeos'[not(
        S[A] == '-' and
        len(S[:A]) == A and S[:A].isdecimal() and
        len(S[A + 1:]) == B and S[A + 1:].isdecimal()
    )::2])


main()