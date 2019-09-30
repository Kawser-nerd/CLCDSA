from collections import defaultdict
from random import shuffle
import sys

def go(filename):
    with open(filename) as f:
        with open("out.txt", "w") as output:
            for case in range(1, int(f.readline()) + 1):
                output.write("Case #%s: " % case)
                input = [int(v) for v in f.readline().split()]
                boosters = input[0]
                build_t = input[1]
                stars = input[2]
                pattern = input[4:]
                times = []
                for s in range(stars):
                    times.append(2 * pattern[s % len(pattern)])
                savings = []
                b = build_t
                for s in range(stars):
                    t = times[s]
                    if b > 0:
                        t -= b
                    if t > 0:
                        t /= 2
                    else:
                        t = 0
                    savings.append(t)
                    b -= times[s]                            
                savings.sort(reverse=True)
                output.write("%s\n" % (sum(times) - sum(savings[0:boosters])))
                print case
                
                           

def main():
    if len(sys.argv) < 1:
        print "Usage: %s <filename>" % os.path.basename(sys.argv[0])
    else:
        go(sys.argv[1])

if __name__ == "__main__":
    main()
