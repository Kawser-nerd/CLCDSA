directions = ['left', 'up', 'right', 'down']

#directions = ['down', 'right', 'up', 'left']
def solve(W, H, B, cells):
    """ solve the problem """

    def down(i, j):
        if i - 1 >=0 and cells[i-1][j] == 1:
            stack.append((i-1, j, 'down'))
    def right(i, j):
        if j + 1 < W and cells[i][j+1] == 1:
            stack.append((i, j+1, 'right'))
    def up(i, j):
        if i + 1 < H and cells[i+1][j] == 1:
            stack.append((i+1, j, 'up'))
    def left(i, j):
        if j - 1 >=0 and cells[i][j-1] == 1:
            stack.append((i, j-1, 'left'))

    #for c in cells: print(c)
    count = 0
    #for c in cells:print(c)
    for _j in range(W):
        if cells[0][_j] == 0: continue
        cells[0][_j] = 0
        i = 0
        j = _j
        stack = []
        # up
        if i + 1 < H and cells[i+1][j] == 1:
            stack.append((i+1, j, 'up'))
        while stack:
            i, j, d = stack.pop() 
            #print(i, j)
            #print(i, j)
            if cells[i][j] == 0: continue

            cells[i][j] = 0
            if i == H-1: 
                count += 1
                break

            f = directions.index(d)
            _directions = [directions[(f + offset + 3) % 4] for offset in range(4)]
            for dd in reversed(_directions):
                eval(dd)(i, j)
    return count


def parse():
    """ parse input """

    W, H, B = map(int, input().split(' '))
    cells = [[1 for w in range(W)] for h in range(H)]
    for b in range(B):
        x0, y0, x1, y1 = map(int, input().split(' ')) 
        for x in range(x0, x1+1):
            for y in range(y0, y1+1):
                cells[y][x] = 0

    return W, H, B, cells


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
