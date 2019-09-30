import sys, itertools
from pprint import pprint
from collections import defaultdict
import operator

output_line = "Case #{X:d}: {K:d}"

def is_board(bark, row, col, size):
    for ri in range(row, row + size):
        for ci in range(col, col + size):
            if bark[ri][ci] == None: #already stripped!
                return False
            #check square to right
            if ri < row + size - 1:
                if bark[ri][ci] == bark[ri + 1][ci]:
                    return False
            #check square below
            if ci < col + size - 1:
                if bark[ri][ci] == bark[ri][ci + 1]:
                    return False
    return True

if __name__ == "__main__":
    infile, outfile = sys.argv[1:]
    with open(infile, "r") as inhandle, open(outfile, "w") as outhandle:
        T = int(inhandle.readline())
        for t in range(T):
            M, N = map(int, inhandle.readline().split())

            bark = []
            for m in range(M):
                row = int(inhandle.readline(), 16)
                bark.append([operator.truth(row & (2 ** x)) for x in reversed(range(N))])
            pprint(bark)

            board_sizes = defaultdict(lambda:0)
            for size in reversed(range(1, min(M, N) + 1)):
                for row in range(M - size + 1):
                    for col in range(N - size + 1):
                        if is_board(bark, row, col, size):
                            board_sizes[size] += 1

                            #now remove that spot from the bark
                            for ri in range(row, row + size):
                                for ci in range(col, col + size):
                                    bark[ri][ci] = None


            print(output_line.format(X=t + 1, K=len(board_sizes)), file=outhandle)
            for size in sorted(board_sizes.keys(), reverse=True):
                print(size, board_sizes[size], file=outhandle)
