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
    num_tribes = read_int()
    tribes = []
    for i in range(num_tribes):
        tribes.append(read_ints())
    return [tribes]

def solve(tribes):
    wall = {}
    result = 0
    today = 0
    tribes.sort()
    keep_going = True
    while keep_going:
        keep_going = False
        needs_repair = set()
        for e, tribe in enumerate(tribes):
            day, num_attacks, west, east, strength, day_delta, travel_delta, strength_delta = tribe
            if day == today:
                succeeds = False
                for i in range(west, east):
                    if i not in wall or strength > wall[i][0]:
                        succeeds = True
                        new_strength = max(wall[i][1] if i in wall else 0, strength)
                        wall[i] = [wall[i][0] if i in wall else 0, new_strength]
                        needs_repair.add(i)        
                
                if succeeds:
                    result += 1
                
                num_attacks -= 1
                if num_attacks:
                    day += day_delta
                    west += travel_delta
                    east += travel_delta
                    strength += strength_delta
            if day > today:
                keep_going = True
                    
            tribes[e] = [day, num_attacks, west, east, strength, day_delta, travel_delta, strength_delta]
        
        for i in needs_repair:
            wall[i][0] = wall[i][1]
        tribes.sort()
        today += 1
    return result            

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