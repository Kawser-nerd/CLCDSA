#!/usr/bin/env python
import sys
from collections import defaultdict

def update_counters(counters,new_digit):
    # Counters is a mapping: (current number, current_power_of_10, sigma % 210): num_options
    # Our options: add the digit to the current number (in the left side)
    # Add the current number to the sigma (plus/minus) and put the new_digit as
    # the current number
    new_counters = defaultdict(int)
    if len(counters) == 0:
        new_counters[(new_digit,10,0)] = 1
    for k in counters:
        #Option 1: add digit to the left
        new_k = (k[0]+new_digit*k[1],k[1]*10,k[2])
        #print new_k, new_counters[new_k]
        new_counters[new_k] += counters[k]
        # Option 2: plus
        new_k = (new_digit,10,(k[2]+k[0])%210)
        #print new_k, new_counters[new_k]
        new_counters[new_k] += counters[k]
        # Option 3: minus
        new_k = (new_digit,10,(k[2]-k[0])%210)
        #print new_k, new_counters[new_k]
        new_counters[new_k] += counters[k]
    
    return new_counters

def count_it(digits_array):
    counters = {}
    for d in reversed(digits_array):
        counters = update_counters(counters,int(d))
    return counters

def is_key_ugly(k):
    sigma = k[0]+k[2]
    if sigma % 2 == 0 or sigma % 3 == 0 or sigma % 5 == 0 or sigma % 7 == 0:
        return True
    return False

def analyze_counters(counters):
    ugly_count = 0
    for k in counters:
        if is_key_ugly(k):
            #print "Adding",k, counters[k]
            ugly_count += counters[k]
    return ugly_count

def do_it_all(digits):
    return analyze_counters(count_it(digits))

import psyco
psyco.full()

lines = open(sys.argv[1]).readlines()
prob_count = int(lines[0])
lines = lines[1:]
assert(len(lines) == prob_count)
for i,l in enumerate(lines):    
    print "Case #%d: %d" % (i+1,do_it_all(l.strip()))
