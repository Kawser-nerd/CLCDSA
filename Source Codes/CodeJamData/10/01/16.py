#!/usr/bin/python

from __future__ import print_function

import sys

def main(filename):
    with open(filename, "r") as f:
        for case, line in enumerate(f):
            if not case:
                T = int(line.strip())
                continue
            if case > T:
                break
            N, K = (int(c) for c in line.split())
            state = K % (2**N)
            print("Case #{0}: {1}".format(case, ("ON" if state==(2**N)-1 else "OFF")))


if __name__ == "__main__":
    main(sys.argv[1])
    sys.exit(0)

