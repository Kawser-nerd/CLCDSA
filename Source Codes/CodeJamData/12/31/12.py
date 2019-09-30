from optparse import OptionParser
import string

def solve(N,C):
    inherits_cache = {}
    for i in range(N):
        if i in inherits_cache:
            continue
        if fill_inherits_list(i, C, inherits_cache):
            return "Yes"
    return "No"

def fill_inherits_list(i, C, inherits_cache):
    inherits_from = set()
    for j in C[i]:
        if j in inherits_from:
            return True
        inherits_from.add(j)
        if j not in inherits_cache:
            match_found = fill_inherits_list(j, C, inherits_cache)
            if match_found:
                return True
        if inherits_from.intersection(inherits_cache[j]):
            return True
        inherits_from = inherits_from.union(inherits_cache[j])
    inherits_cache[i] = inherits_from
    return False

def parse_case(input_file):
    N = int(input_file.readline())
    C = []
    for i in range(N):
        data_line = input_file.readline()
        bits = data_line.split()
        C.append([(int(x) - 1) for x in bits[1:]])
    return N,C

def main():
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