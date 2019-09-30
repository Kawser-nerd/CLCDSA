from collections import defaultdict
from random import shuffle
import sys

def go(filename):
    with open(filename) as f:
        with open("out.txt", "w") as output:
            for case in range(1, int(f.readline()) + 1):
                output.write("Case #%s:\n" % case)
                failed = False
                rc = f.readline().split()
                nr = int(rc[0])
                nc = int(rc[1])
                rows = []   
                for i in range(nr):
                    rows.append([v for v in f.readline() if v != '\n'])
                print rows
                for r in range(nr):              
                    for c in range(nc):
                        print r, c
                        if rows[r][c] == "#":
                            if r < nr - 1 and c < nc - 1 and rows[r][c + 1] == rows[r + 1][c] == rows[r + 1][c + 1] == "#":
                                rows[r][c] = "/"
                                rows[r][c + 1] = "\\"
                                rows[r + 1][c] = "\\"
                                rows[r + 1][c + 1] = "/"
                            else:
                                failed = True
                if failed:
                    output.write("Impossible\n")
                else:
                    for r in range(nr):
                        output.write("%s\n" % "".join(rows[r]))
                
                           

def main():
    if len(sys.argv) < 1:
        print "Usage: %s <filename>" % os.path.basename(sys.argv[0])
    else:
        go(sys.argv[1])

if __name__ == "__main__":
    main()
