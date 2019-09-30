def main():
    A, B = map(int, input().split())
    S = input()
    s = S.split('-')
    if len(s) != 2:
        print('No')
    else:
        x = s[0]
        y = s[1]
        print(
            'YNeos'[
                not (
                    len(x) == A and
                    len(y) == B and
                    x.isdecimal() and
                    y.isdecimal()
                )::2
            ]
        )


main()