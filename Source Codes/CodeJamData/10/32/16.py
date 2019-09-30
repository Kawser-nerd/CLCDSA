import sys, itertools
from pprint import pprint
from collections import namedtuple
import math
from decimal import Decimal
from fractions import Fraction

output_line = "Case #{X:d}: {Y:d}"

Rope = namedtuple("Rope", "a b")

if __name__ == "__main__":
    infile, outfile = sys.argv[1:]
    with open(infile, "r") as inhandle, open(outfile, "w") as outhandle:
        T = int(inhandle.readline())
        for t in range(T):
            L, P, C = map(int, inhandle.readline().split())

            stage1 = math.log(Fraction(P, L), C)
            stage2 = math.log(stage1, 2)
            num_tests = max(0, math.ceil(stage2))
            print(stage1, stage2, num_tests)

            print(output_line.format(X=t + 1, Y=num_tests), file=outhandle)
