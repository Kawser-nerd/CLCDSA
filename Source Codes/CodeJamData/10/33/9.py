#!/usr/bin/python

import sys

INPUT = sys.stdin
INPUT = open(sys.argv[1],'r')

def getline():
    return INPUT.readline()[:-1]

def trace(*strs):
    return
    print >> sys.stderr, '..',
    for str in strs:
        print >> sys.stderr, str,
    print >> sys.stderr

def memoize(f):
    memos = {}
    def memoized_f( *args ):
        try:
            result = memos[args]
            trace(args, ": got result from memo")
        except KeyError:
            result = f(*args)
            trace(args, ": got result by calling")
            memos[args] = result
        return result
    return memoized_f

n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    trace( 'Case #', case_num )

    expansion_ = {
        '0': '####',
        '1': '### ',
        '2': '## #',
        '3': '##  ',
        '4': '# ##',
        '5': '# # ',
        '6': '#  #',
        '7': '#   ',
        '8': ' ###',
        '9': ' ## ',
        'A': ' # #',
        'B': ' #  ',
        'C': '  ##',
        'D': '  # ',
        'E': '   #',
        'F': '    ',
    }

    (M,N) = map(int, getline().split())
    trace( 'M=%s, N=%s' % (M,N) )
    assert N % 4 == 0
    row_ = []
    for m in range(M):
        line = getline()
        trace(line)
        assert len(line) == N/4
        bits = list(''.join( expansion_[c] for c in line ))
        row_.append(bits)

    def print_board():
        for r in range(M):
            print ''.join(row_[r])

    if 0:
        print_board()

    def get_size_of_largest_chessboard_based_at(r,c,s_bound):
        # inefficient!
        best_s_sofar = None
        for s in range(1, 1+s_bound):
            if is_chessboard(r,c,s):
                best_s_sofar = s
            else:
                break
        assert best_s_sofar is not None
        return best_s_sofar

    def is_chessboard(r,c,s):
        for rr in range(r,r+s):
            for cc in range(c,c+s):
                if (
                    (((rr - r) + (cc - c)) % 2 == 0)
                    != 
                    (row_[rr][cc] == row_[r][c])
                ):
                    return False
        return True

    # For each cell,
    # determine the size of the largest chessboard
    # having that cell as its top-leftmost.
    largest_based_at_ = [ [0] * N for r in range(M) ]
    for r in range(M):
        row = row_[r]
        for c in range(N):
            # cell r,c
            largest_based_at_[r][c] = get_size_of_largest_chessboard_based_at(r, c, min(M-r, N-c))

    if 0:
        for r in range(M):
            for c in range(N):
                print '%2d' % largest_based_at_[r][c],
            print


    max_s = 0
    squares_of_size_ = {}
    for r in range(M):
        for c in range(N):
            s = largest_based_at_[r][c]
            if s not in squares_of_size_:
                squares_of_size_[s] = []
            squares_of_size_[s].append( (r,c) )
            max_s = max(max_s,s)

    def square_is_intact(r,c,s):
        for rr in range(r,r+s):
            for cc in range(c,c+s):
                if row_[rr][cc] == 'X':
                    return False
        return True

    def cut_out_square(r,c,s):
        trace('cut_out_square:', r, c, s)
        for rr in range(r,r+s):
            for cc in range(c,c+s):
                row_[rr][cc] = 'X'

    cut_squares_of_size_ = {}
    for s in range(max_s,0,-1):
        trace('s:',s)
        squares = sorted(squares_of_size_[s])
        trace(squares)
        for (r,c) in squares:
            # if r==2 and c==1: import pdb; pdb.set_trace()
            if square_is_intact(r,c,s):
                cut_out_square(r,c,s)
                if s not in cut_squares_of_size_:
                    cut_squares_of_size_[s] = 1
                else:
                    cut_squares_of_size_[s] += 1
            elif s > 1:
                new_s = get_size_of_largest_chessboard_based_at(r, c, s-1)
                squares_of_size_[new_s].append( (r,c) )

    # print_board()

    for r in range(M):
        for c in range(N):
            assert row_[r][c] == 'X'

    K = len(cut_squares_of_size_)
    print 'Case #%d: %s' % (case_num, K)
    for (s,count) in reversed(sorted(cut_squares_of_size_.items())):
        print s, count

    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
