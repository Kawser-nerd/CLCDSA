# MISC
read_int = lambda:int(raw_input().strip())
read_ints = lambda:[int(x) for x in raw_input().split()]
count_to = lambda n:xrange(1,n+1)

# GENERAL GRID TOOLS
def read_grid(rows, columns, parse_cell=None):
    if parse_cell is None:
        parse_cell = lambda x:x
    grid = {}
    for r in count_to(rows):
        rowstring = raw_input()
        for c in count_to(columns):
            grid[r,c] = parse_cell(rowstring[c-1])
    return grid

def print_grid(rows, columns, grid, f=None):
    if f is None:
        f = lambda x:x
    for r in count_to(rows):
        print "".join(f(grid[r,c]) for c in count_to(columns))

def create_grid(rows, columns, f):
    return dict(
        ((r,c), f(r,c))
        for r in count_to(rows)
        for c in count_to(columns))

# GENERAL SOLVE LOOP
def solve_all(solve):
    num_cases = read_int()
    for i in count_to(num_cases):
         print "Case #{0}:".format(i),
         solve()

# SOLUTION
def rotate_diamond(d):
    k = 1+len(d)//2
    d2 = [[] for i in xrange(len(d))]
    mid = k - 1
    for line in d:
        start = 1+len(d)//2-len(line)
        for i in xrange(len(line)):
            d2[start+2*i].append(line[i])
    return d2

def flip_diamond(d):
    return list(reversed(d))

def match(shorter,longer):
    delta = (len(longer)-len(shorter))//2
    return all(shorter[i]==longer[i+delta] for i in xrange(len(shorter)))

def naive_psuedo_symm(d, k, line_no):
    sub_k = line_no + 1
    for i in xrange(line_no):
        mirror_line = 2 * line_no - i
        if not match(d[i], d[mirror_line]):
            return False
    return True

def analyse_symm(d, k):
    d2 = flip_diamond(d)
    for i in xrange(0,k):
        for dd in (d,d2):
            if naive_psuedo_symm(dd,k,k-i-1):
                return k-i-1
    raise Exception("OOPS")

def cost(small_k, big_k):
    return big_k * big_k - small_k * small_k

def solve_case():
    k = read_int()
    diamond = [read_ints() for i in count_to(2*k-1)]
    flipped = flip_diamond(diamond)

    vsymm = analyse_symm(diamond, k)
    hsymm = analyse_symm(rotate_diamond(diamond), k)
    big_k = k + (k-1)*2 - vsymm - hsymm
    print cost(k, big_k)
solve_all(solve_case)
