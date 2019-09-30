from collections import defaultdict
from random import shuffle
import sys

def go(filename):
    with open(filename) as f:
        with open("out.txt", "w") as output:
            for case in range(1, int(f.readline()) + 1):
                output.write("Case #%s: " % case)
                in1 = [int(v) for v in f.readline().split()]
                l, h = in1[1], in1[2]
                jeff = []
                for i in range(l, h + 1):
                    jeff.append(i)
                players = [int(v) for v in f.readline().split()]
                for p in players:
                    nj = []
                    for j in jeff:
                        if (j >= p and j % p == 0) or (j < p and p % j == 0):
                            nj.append(j)
                    jeff = nj
                    if not jeff:
                        output.write("NO\n")
                        break
                else:
                    output.write("%s\n" % jeff[0])     

def main():
    if len(sys.argv) < 1:
        print "Usage: %s <filename>" % os.path.basename(sys.argv[0])
    else:
        go(sys.argv[1])

if __name__ == "__main__":
    main()
