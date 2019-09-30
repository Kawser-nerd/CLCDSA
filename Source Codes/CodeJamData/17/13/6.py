#! /usr/bin/python

import sys
from collections import deque

def read_case(f):
    return read_space_line(f, int) 

def moves(state, b, d, hd_orig):
    # returns the possible next states.
    hd, ad, hk, ak = state
    return [
             (hd-ak, ad, hk-ad, ak), # attack
             (hd-ak, ad+b, hk, ak), # Buff
             (hd_orig-ak, ad, hk, ak), # Cure
             (hd-max(0, ak-d), ad, hk, max(0, ak-d)), # Debuff
    ]

def solve(case):
    hd, ad, hk, ak, b, d = case
    hd_orig = hd
    # Try caching the shit out of this, DFS on states.
    # (hd, ad, hk, ak)
    seen = {}
    to_see = deque()
    memo = {}
    to_see.appendleft((hd, ad, hk, ak))
    seen[(hd, ad, hk, ak)] = 0
    while to_see:
        state = to_see.pop()
        num_moves = seen[state] + 1
        for move in moves(state, b, d, hd_orig):
            hd, ad, hk, ak = move
            if hk <= 0:
                # We won!
                return num_moves
            if hd > 0:
                # We survived to fight another round.
                if move not in seen:
                    seen[move] = num_moves
                    to_see.appendleft(move)

    # We've exhausted the search :(
    return "IMPOSSIBLE"

# Edit over here --------

def read_space_line(f, constr):
    # Reads a space-delimited line with constructor.
    line = f.readline().strip().split(' ')
    return tuple(int(x) for x in line)

def read_line(f, constr):
    return constr(f.readline().strip())

def input_iterator(in_fn):
    with open(in_fn) as f:
        num_cases = read_line(f, int)
        for i in range(num_cases):
            yield read_case(f)

def write_output(f, case_n, sol_str):
    f.write("Case #%d: %s\n" % (case_n, sol_str))

def main():
    in_fn = sys.argv[1] 
    out_fn = sys.argv[2]
    
    with open(out_fn, 'w') as out_f:
        for i, case in enumerate(input_iterator(in_fn)):
            sol_str = solve(case)
            write_output(out_f, i+1, sol_str)

if __name__ == "__main__":
    main()


