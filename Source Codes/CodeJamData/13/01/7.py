#!/usr/bin/python3.2

import sys

if len(sys.argv) == 1:
    f = sys.stdin
    o = sys.stdout

if len(sys.argv) == 2:
    f = open(sys.argv[1], 'r')
    o = sys.stdout

if len(sys.argv) == 3:
    f = open(sys.argv[1], 'r')
    o = open(sys.argv[2], 'w')

def check_line(l):
    player_x = 0
    player_y = 0

    if all([c=='T' or c=='X' for c in l]):
        player_x += 1
    if all([c=='T' or c=='O' for c in l]):
        player_y += 1

    return (player_x, player_y)

def do_tic_tac_to(lines, case_id):
    player_x = 0
    player_y = 0

    # Check lines
    for l in lines:
        (px, py) = check_line(l)
        player_x = px + player_x
        player_y = py + player_y

    # Check cols
    for col in range(4):
        l = [l[col] for l in lines]
        (px, py) = check_line(l)
        player_x = px + player_x
        player_y = py + player_y

    # Check diags
    l = [lines[i][i] for i in range(4)]
    (px, py) = check_line(l)
    player_x = px + player_x
    player_y = py + player_y

    l = [lines[3-i][i] for i in range(4)]
    (px, py) = check_line(l)
    player_x = px + player_x
    player_y = py + player_y

    # Not finished
    grid_full = not any([c == '.' for c in ''.join(lines)])

    if player_x == 0 and player_y == 0:
        if grid_full:
            print('Case #%d: Draw' % case_id, file = o)
        else:
            print('Case #%d: Game has not completed' % case_id, file = o)
        return

    if player_x > player_y:
        print('Case #%d: X won' % case_id, file = o)
    else:
        print('Case #%d: O won' % case_id, file = o)


case_id = 1
nb = int(f.readline().strip())
for t in range(nb):
    lines = []
    for x in range(5):
        line = f.readline().strip()
        lines.append(line)

    do_tic_tac_to(lines[:-1], case_id)
    case_id += 1

    #s = "Case #%d: %s\n" % (t+1, res)
    #o.write(s)
    #print(s)
