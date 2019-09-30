import argparse
import collections
import fractions
import functools
import itertools
import math
import operator

from sys import exit, stdin
from multiprocessing import Pool

def solve_star(args):
    return solve(*args)

def read_int():
    return int(stdin.readline().strip())

def read_ints():
    return [int(n) for n in stdin.readline().strip().split()]

def read_words():
    return stdin.readline().strip()

def parse():
    name, n = read_words().split()
    return [name, int(n)]

def solve(name, n):
    vowels = ["a", "e", "i", "o", "u"]
    count = 0
    last = 0 
    total = 0
    for e, c in enumerate(name):
        if c in vowels:
            count = 0
        else:
            count += 1
            if count == n:
                this_string_starts = e - (n - 1)
                total += (this_string_starts - last + 1) * (len(name) - e)
                last = this_string_starts + 1
                count -= 1
    return total
                

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser()
    parser.add_argument("-m", "--multi", help="turn on multiprocessing", action="store_true")
    args = parser.parse_args()
    
    with open("out.txt", "w") as f:
        if args.multi:
            pool = Pool()
            iter = pool.imap(solve_star, (parse() for i in range(read_int())))
            for i, result in enumerate(iter):
                s = "Case #{}: {}".format(i + 1, result)
                print(s)
                f.write(s + "\n")
        
        else:
            for i in range(read_int()):
                s = "Case #{}: {}".format(i + 1, solve(*parse()))
                print(s)
                f.write(s + "\n")