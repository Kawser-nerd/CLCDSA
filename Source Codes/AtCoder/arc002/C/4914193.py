from itertools import product

BUTTONS = ['A', 'B', 'X', 'Y']
LR_PATTERNS = list(product(BUTTONS, BUTTONS))


def main():
    N = int(input())
    commands = input().rstrip()

    minimum = len(commands)
    for i, l in enumerate(LR_PATTERNS):
        for j, r in enumerate(LR_PATTERNS):
            if i == j:
                continue

            tmp = len(commands.replace("".join(l), 'L').replace("".join(r), 'R'))
            if tmp < minimum:
                minimum = tmp

    print("{}".format(minimum))


if __name__ == '__main__':
    main()