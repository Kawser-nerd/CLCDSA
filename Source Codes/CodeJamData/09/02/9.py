# -*- coding: utf-8 -*-

from pprint import pprint

VERBOSE = True
VERBOSE = False

class Encoder(object):
    def __init__(self):
        self.known = dict()
        self.next = 'a'
    def encode(self, key):
        if not (key in self.known):
            self.known[key] = self.next
            self.next = chr(ord(self.next) + 1)
        return self.known[key]

def solve(h, w, altitudes):
    # Giving unique id to every pos
    struc = [ [ row_no * w + col_no for col_no in xrange(0, w) ]
              for row_no in xrange(0, h) ]

    def neighbours(row, col):
        r = []
        if row > 0:   r.append( (row-1, col) )
        if col > 0:   r.append( (row, col-1) )
        if col < w-1: r.append( (row, col+1) )
        if row < h-1: r.append( (row+1, col) )
        return r

    if VERBOSE: 
        print "Alt"
        pprint(altitudes)

    while True:
        changed_count = 0
        if VERBOSE:  pprint(struc)
        for row_no in xrange(0, h):
            for col_no in xrange(0, w):
                min_r, min_c = row_no, col_no
                here_val = altitudes[row_no][col_no] 
                min_val = here_val
                for x, y in neighbours(row_no, col_no):
                    a = altitudes[x][y]
                    if a < min_val:
                        min_val = a
                        min_r, min_c = x, y
                if min_val < here_val:
                    if struc[row_no][col_no] != struc[min_r][min_c]:
                        changed_count += 1
                        struc[row_no][col_no] = struc[min_r][min_c]
        if not changed_count:
            break

    encoder = Encoder()
    return [ [ encoder.encode(val) for val in row ]
             for row in struc ]


if __name__ == "__main__":
    import sys
    if not len(sys.argv) == 2:
        raise Exception("Give input as parameter")

    input = open(sys.argv[1])

    map_count = int(input.readline())

    for map_no in xrange(0, map_count):
        h, w = (int(x) for x in input.readline().split())
        altitudes = [
            [ int(t) for t in input.readline().split() ]
            for line_no in xrange(0,h)
            ]

        print "Case #%d:" % (map_no + 1)
        for result_row in solve(h, w, altitudes):
            print " ".join(result_row)
