def main():
    inits = []
    for i in range(8):
        s = input()
        for j, c in enumerate(s):
            if c == 'Q':
                inits.append((i, j))

    answer = solve(inits)
    if answer:
        for i in range(8):
            line = []
            for j in range(8):
                if (i, j) in answer:
                    line.append('Q')
                else:
                    line.append('.')
            print(''.join(line))
    else:
        print('No Answer')


def solve(inits):
    m = set()
    for i in range(8):
        for j in range(8):
            m.add((i, j))

    for init in inits:
        if init not in m:
            return False
        m = m - queen_route(*init)

    return search(inits, m)

def search(queens, m):
    if len(queens) == 8:
        return queens
    
    for pos in m:
        r = search(queens + [pos], m - queen_route(*pos))
        if r:
            return r

    return None

def queen_route(y, x):
    s = set()
    for i in range(8):
        s.add((i, x))
        s.add((y, i))

        j = y - x + i
        if 0 <= j < 8:
            s.add((j, i))

        j = x + y - i
        if 0 <= j < 8:
            s.add((j, i))

    return s


main()