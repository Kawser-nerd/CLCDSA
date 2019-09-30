from copy import deepcopy
from itertools import product, chain


def na():
    print("No Answer")
    exit()


def draw(a, x, y):
    _a = deepcopy(a)
    for i in range(1, 8):
        for dx, dy in chain(product((-i, i), (-i, i)), product((-i, i), [0]), product([0], (-i, i))):
            if _a[y+dy][x+dx] == "Q":
                return False
            _a[y+dy][x+dx] = "*"

    _a[y][x] = "Q"
    return _a


def answer(a):
    print(*(["".join(["." if c=="*" else c for c in l[7:15]]) for l in a[7:15]]), sep="\n")
    exit()


def rec(a, y):
    if y == 15:
        answer(a)
    if "Q" in a[y]:
        rec(a, y+1)
        return
    for x in range(7, 15):
        if a[y][x] != "Q":
            _a = draw(a, x, y)
            if _a:
                rec(_a, y+1)


if __name__ == "__main__":
    square = [["."]*22 for _ in [0]*7] +\
             [list("."*7+input()+"."*7) for _ in [0]*8] + [["."]*22 for _ in [0]*7]

    for y in range(7, 15):
        cnt = square[y].count("Q")
        if cnt > 1:
            na()
        elif cnt:
            x = square[y].index("Q")
            square = draw(square, x, y)
            if not square:
                na()

    rec(square, 7)
    na()