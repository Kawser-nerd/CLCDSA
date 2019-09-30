def c(p, g, lis):
    for e in lis:
        if p <= g:
            p += e
        else:
            p -= e
    return p == g


if __name__ == '__main__':
    s = input()
    gx, gy = map(int, input().split())

    s = s.split("T")
    s = [len(_) for _ in s]

    x_move = s[::2]
    y_move = s[1::2]

    x = x_move.pop(0)
    y = 0

    x_move.sort(reverse=True)
    y_move.sort(reverse=True)

    if c(x, gx, x_move) and c(y, gy, y_move):
        print("Yes")
    else:
        print("No")