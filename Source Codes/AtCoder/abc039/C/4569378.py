def solve(s):
    pattern = ("WBWBWWBWBWBW" * 10)
    oto = [
    "Do",
    "Do",
    "Re",
    "Re",
    "Mi",
    "Fa",
    "Fa",
    "So",
    "So",
    "La",
    "La",
    "Si"
    ]
    i = pattern.find(s)
    return oto[i]


def main():
    print(solve(input()))


if __name__ == '__main__':
    main()