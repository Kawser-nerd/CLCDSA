from optparse import OptionParser
import string

def solve(N,M,A,B):
    cache = {}
    return best_toy_count(A, B, 0, 0, A[0], A[1], B[0], B[1], len(A), len(B), cache)

def best_toy_count(A,B, ai, bi, al, at, bl, bt, la, lb, cache):
    cache_index = (ai,bi,al,bl)
    if (cache_index in cache):
        return cache[cache_index]
    toys = 0
    new_toys = 0
    next_ai = ai + 2;
    next_bi = bi + 2;
    if (at == bt):
        if al < bl:
            new_toys = al
            if next_ai < la:
                new_toys += best_toy_count(A,B, next_ai, bi, A[next_ai], A[next_ai + 1], bl - al, bt, la, lb,cache)
        else:
            new_toys = bl
            if next_bi < lb:
                new_toys += best_toy_count(A,B, ai, next_bi, al - bl, at, B[next_bi], B[next_bi + 1], la, lb, cache)
        cache[cache_index] = new_toys
        return new_toys
    else:
        if next_ai < la:
            pot_a = best_toy_count(A,B, next_ai, bi, A[next_ai], A[next_ai + 1], bl, bt, la, lb, cache)
        else:
            pot_a = 0
        if next_bi < lb:
            pot_b = best_toy_count(A,B, ai, next_bi, al, at, B[next_bi], B[next_bi + 1], la, lb, cache)
        else:
            pot_b = 0
        cache[cache_index] = max([pot_a,pot_b])
        return cache[cache_index]


def parse_case(input_file):
    data_line = input_file.readline()
    bits = data_line.split()
    N = int(bits[0])
    M = int(bits[1])
    data_line = input_file.readline()
    A = [int(x) for x in data_line.split()]
    data_line = input_file.readline()
    B = [int(x) for x in data_line.split()]
    return N, M, A, B

def main():
    import sys
    sys.setrecursionlimit(1000000000)
    parser = OptionParser()
    parser.add_option("-f", "--file", dest="filename",
                      help="read input from FILE", metavar="FILE")

    (options, args) = parser.parse_args()
    if not options.filename:
        parser.error("Must provide a filename.")
    input_file = open(options.filename, "r")
    total_cases = int(input_file.readline())
    case_number = 0
    while case_number < total_cases:
    	case_number += 1
    	data_args = parse_case(input_file)
    	print "Case #%d: %s" % (case_number, solve(*data_args))

if __name__ == "__main__":
	main()