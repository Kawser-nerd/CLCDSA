from copy import deepcopy

coord1 = []
coord2 = []


def visit(y, x):
    global coord2
    if y < 0 or 10 <= y or x < 0 or 10 <= x:
        return
    if not coord2[y][x]:
        return
    coord2[y][x] = False
    visit(y - 1, x)
    visit(y + 1, x)
    visit(y, x - 1)
    visit(y, x + 1)


def check():
    global coord2
    for y in range(10):
        for x in range(10):
            if coord2[y][x]:
                return False
    return True


def main():
    global coord1, coord2
    for _ in range(10):
        coord1.append([c == "o" for c in input()])

    checked = False
    for y in range(10):
        for x in range(10):
            if not coord1[y][x]:
                continue
            coord2 = deepcopy(coord1)
            visit(y, x)
            if check():
                print("YES")
                return
            checked = True
        if checked:
            break

    for y in range(10):
        for x in range(10):
            if coord1[y][x]:
                continue
            coord1[y][x] = True
            coord2 = deepcopy(coord1)
            visit(y, x)
            if check():
                print("YES")
                return
            coord1[y][x] = False
    print("NO")


if __name__ == "__main__":
    main()