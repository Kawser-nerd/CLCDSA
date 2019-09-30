import sys

PHRASE = 'welcome to code jam'
MEMOIZATION_DICT = {}

def rec_count_subseqs(line, subseq, line_offset, subseq_offset):
    assert line_offset <= len(line) and subseq_offset <= len(subseq)
    global MEMOIZATION_DICT
    
    args = (line_offset, subseq_offset)
    if args in MEMOIZATION_DICT:
        return MEMOIZATION_DICT[args]
    
    if subseq_offset == len(subseq):
        count = 1
    elif line_offset == len(line):
        count = 0
    else:
        count = 0
        for i in range(line_offset, len(line)):
            if line[i] == subseq[subseq_offset]:
                count += rec_count_subseqs(line, subseq, i+1, subseq_offset+1)
    
    MEMOIZATION_DICT[args] = count
    return count

def solve_case(in_fp):
    global MEMOIZATION_DICT
    MEMOIZATION_DICT = {}
    line = in_fp.readline().strip()
    subseq_count = rec_count_subseqs(line, PHRASE, 0, 0)
    return '%04d' % (subseq_count % 10000)

def main(argv):
    sys.setrecursionlimit(100000)
    
    in_fp = open(argv[1], 'rb')
    out_fp = open(argv[2], 'wb')

    num_cases = int(in_fp.readline())
    for i in range(num_cases):
        solution = solve_case(in_fp)
        out_fp.write('Case #%d: %s\n' % (i+1, solution))
    
    in_fp.close()
    out_fp.close()

if __name__ == '__main__':
    main(sys.argv)
