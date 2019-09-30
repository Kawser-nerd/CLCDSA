#!/usr/bin/env python

def check_seq(seq):
    if seq.replace('T', 'X') == 'XXXX': return 'X won'
    if seq.replace('T', 'O') == 'OOOO': return 'O won'
    return False

def check_game(game):
    x_win = 'XXXX'
    o_win = 'OOOO'
    # Rows:
    for r in range(4):
        res = check_seq(game[4*r:4*r+4])
        if res: return res
    # Cols:
    for c in range(4):
        res = check_seq(game[c::4])
        if res: return res
    # Diagonals:
    res = check_seq(game[0::5])
    if res: return res
    res = check_seq(game[3:13:3])
    if res: return res
    # Not completed or draw:
    if '.' in game:
        return 'Game has not completed'
    return 'Draw'

cases_count = int(raw_input())
for i in range(cases_count):
    game = ''.join(raw_input() for i in range(5))
    print "Case #%d: %s" % (i+1, check_game(game))
