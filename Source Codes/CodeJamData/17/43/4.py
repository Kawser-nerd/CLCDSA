# need to determine if there's any rotation of beam shooters that covers all
# empty cells in house
#
# two parts: (1) determine set of cells covered by each beam, in form of bit vector
# (2) see if there's cover ??? sort of 2sat ish? might get away with being
# greedy

# bit vector might be problematic... there are at most 2500 cells in the map
# there are definitely maps where every cell is covered under some rotation but it's impossible to satisfy all of them:
# ####
# #.##
# #|.#
# ####

class Splodey(Exception): pass

class Map(object):
    def __init__(self, cells):
        self.nr = len(cells)
        self.nc = len(cells[0])
        self.cells = [list(row) for row in cells]

    def __getitem__(self, (r, c)):
        if r in xrange(self.nr) and c in xrange(self.nc):
            return self.cells[r][c]
        else:
            return '#'

    def __setitem__(self, (r, c), cell):
        self.cells[r][c] = cell

    def beam_path(self, r, c, dr, dc):
        result = []
        r += dr
        c += dc
        while True:
            if self[r, c] in '#':
                break
            elif self[r, c] in '-|':
                raise Splodey
            elif self[r, c] == '.':
                result.append((r, c))
            elif self[r, c] == '/':
                dr, dc = -dc, -dr
            elif self[r, c] == '\\':
                dr, dc = dc, dr
            r += dr
            c += dc
        return result

    def beam_cover(self, r, c, cell):
        try:
            if cell == '|':
                result = self.beam_path(r, c, 1, 0)
                result += self.beam_path(r, c, -1, 0)
            else:
                assert cell == '-'
                result = self.beam_path(r, c, 0, 1)
                result += self.beam_path(r, c, 0, -1)
            return sorted(set(result))
        except Splodey:
            return None

    def itercells(self):
        for r in xrange(nr):
            for c in xrange(nc):
                yield r, c, self[r, c]

    def __iter__(self):
        return iter(self.cells)

def solve(cells):
    map = Map(cells)
    covers = []
    for r, c, cell in map.itercells():
        if cell == '-' or cell == '|':
            covers.append((r, c, map.beam_cover(r, c, '-'), map.beam_cover(r, c, '|')))

    cover_counts = dict(((r, c), 0) for (r, c, cell) in map.itercells() if cell == '.')
    for r, c, tc, fc in covers:
        if tc is not None:
            for i in tc:
                cover_counts[i] += 1
        if fc is not None:
            for i in fc:
                cover_counts[i] += 1

    def aux(cover_index):
        if 0 in cover_counts.itervalues():
            return None
        if cover_index == len(covers):
            return []

        r, c, tc, fc = covers[cover_index]
        # try tc
        if tc is not None:
            if fc is not None:
                for i in fc:
                    cover_counts[i] -= 1
            result = aux(cover_index + 1)
            if result is not None:
                return [(r, c, '-')] + result
            if fc is not None:
                for i in fc:
                    cover_counts[i] += 1
        # try fc
        if fc is not None:
            if tc is not None:
                for i in tc:
                    cover_counts[i] -= 1
            result = aux(cover_index + 1)
            if result is not None:
                return [(r, c, '|')] + result
            if tc is not None:
                for i in tc:
                    cover_counts[i] += 1
            return None

    result = aux(0)
    if result is not None:
        for (r, c, cell) in result:
            map[r, c] = cell
        return ('POSSIBLE', map)
    else:
        return ('IMPOSSIBLE', None) # TODO: build result map

if __name__ == '__main__':
    import sys
    fp = open(sys.argv[1])
    def readline():
        return fp.readline().strip()
    num_cases = int(readline())
    for i in xrange(num_cases):
        nr, nc = [int(x) for x in readline().split()]
        cells = [readline() for r in xrange(nr)]
        result, map = solve(cells)
        print "Case #%d: %s" % (i + 1, result)
        if map is not None:
            for row in map:
                print ''.join(row)
