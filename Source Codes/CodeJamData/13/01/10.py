import sys

def winner(a, b, c, d):
    if a == b == c == d:
        if a == 'O':
            print 'O won'
            return True
        elif a == 'X':
            print 'X won'
            return True
        else:
            return False
    elif (a == 'T') + (b == 'T') + (c == 'T') + (d == 'T') == 1:
        if (a == 'O') + (b == 'O') + (c == 'O') + (d == 'O') == 3:
            print 'O won'
            return True
        elif (a == 'X') + (b == 'X') + (c == 'X') + (d == 'X') == 3:
            print 'X won'
            return True
    else:
        return False

for test_case in xrange(1, int(raw_input()) + 1):
    grid = [raw_input(), raw_input(), raw_input(), raw_input()]
    raw_input()

    sys.stdout.write("Case #{0}: ".format(test_case))
    done = False

    for i in xrange(4):
        if winner(grid[i][0], grid[i][1], grid[i][2], grid[i][3]):
            done = True
            break

        if winner(grid[0][i], grid[1][i], grid[2][i], grid[3][i]):
            done = True
            break

    if done:
        continue

    if winner(grid[0][0], grid[1][1], grid[2][2], grid[3][3]):
        continue

    if winner(grid[0][3], grid[1][2], grid[2][1], grid[3][0]):
        continue

    if grid[0].count('.') + grid[1].count('.') + grid[2].count('.') + grid[3].count('.') == 0:
        print 'Draw'
        continue
    else:
        print 'Game has not completed'
        continue
