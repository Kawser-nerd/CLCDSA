import sys, itertools
from pprint import pprint
from collections import namedtuple

output_line = "Case #{X:d}: {Y:d}"

Rope = namedtuple("Rope", "a b")

if __name__ == "__main__":
    infile, outfile = sys.argv[1:]
    with open(infile, "r") as inhandle, open(outfile, "w") as outhandle:
        T = int(inhandle.readline())
        for t in range(T):
            N = int(inhandle.readline())

            ropes = [Rope(*map(int, inhandle.readline().split())) for n in range(N)]

            ropes.sort()

            total = 0
            for ropeA in ropes:
                for ropeB in ropes:
                    if ((ropeA.a < ropeB.a and ropeA.b > ropeB.b)
                        or (ropeA.a > ropeB.a and ropeA.b < ropeB.b)):
                        total += 1


            assert(total % 2 == 0)
            total = total // 2


            print(output_line.format(X=t + 1, Y=total), file=outhandle)
