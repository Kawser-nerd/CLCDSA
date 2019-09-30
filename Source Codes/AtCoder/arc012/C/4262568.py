square = [["."]*29]*5 + [list("."*5+input()+"."*5) for _ in [0]*19] + [["."]*29]*5


def check(square, target):
    l = 4
    backward, forward = lambda x: range(x-l, x+1), lambda x: range(x, x+l+1)

    for y in range(5, 24):
        for x, c in filter(lambda x: x[1] == target, zip(range(5, 24), square[y][5:24])):
            if all(square[y][_x] == target for _x in backward(x)) or\
                    all(square[y][_x] == target for _x in forward(x)) or\
                    all(square[_y][x] == target for _y in backward(y)) or\
                    all(square[_y][x] == target for _y in forward(y)) or\
                    all(square[_y][_x] == target for _y, _x in zip(backward(y), backward(x))) or\
                    all(square[_y][_x] == target for _y, _x in zip(forward(y), forward(x))) or\
                    all(square[_y][_x] == target for _y, _x in zip(backward(y), reversed(forward(x)))) or\
                    all(square[_y][_x] == target for _y, _x in zip(forward(y), reversed(backward(x)))):
                return True
    return False


o_total, x_total = sum(l.count("o") for l in square), sum(l.count("x") for l in square)
o_win = check(square, "o")
x_win = check(square, "x")
if o_win and x_win:
    print("NO")
    exit()

if o_win:
    if x_total != o_total-1:
        print("NO")
        exit()
    flag = False
    for y in range(5, 24):
        for x, c in filter(lambda x: x[1] == "o", zip(range(5, 24), square[y][5:24])):
            square[y][x] = "."
            if not check(square, "o"):
                flag = True
            square[y][x] = "o"
    print("YES" if flag else "NO")

elif x_win:
    if x_total != o_total:
        print("NO")
        exit()
    flag = False
    for y in range(5, 24):
        for x, c in filter(lambda x: x[1] == "x", zip(range(5, 24), square[y][5:24])):
            square[y][x] = "."
            if not check(square, "x"):
                flag = True
            square[y][x] = "x"
    print("YES" if flag else "NO")
else:
    print("YES" if x_total == o_total or x_total == o_total - 1 else "NO")