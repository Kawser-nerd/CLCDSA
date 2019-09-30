#!/usr/bin/python
import os, sys, math

global primes
primes = [2, 3, 5, 7]

def get_prime_factors_small1(value):
    global primes
    factor_count = [0, 0, 0, 0]
    while value > 1:
        for (i, p) in enumerate(primes):
            if p * (value/p) == value:
                factor_count[i] += 1
                value = value / p
    return factor_count

def solve_small1(m, n, values):
    # n = 3, m = 5
    # 3 numbers between 2 and 5 (inclusive)
    min_primes = [0, 0, 0, 0]
    total_primes = [0, 0, 0, 0]
    for v in values:
        factor_count = get_prime_factors_small1(v)
        if (factor_count[0] == 2 and factor_count[1] == 1 and factor_count[2] == 1):
            # _very_ lucky!
            return [4,3,5]
        for i in range(len(min_primes)):
            min_primes[i] = max(min_primes[i], factor_count[i])
            total_primes[i] += factor_count[i]
    #print min_primes
    #print total_primes
    #if sum(min_primes) > 3:
    #    print 'ERROR - min_primes is %s too big for values %s' % (min_primes, values)
    #    sys.exit(1)
    guesses = []
    # 3's and 5's stand alone
    for i in range(min_primes[1]):
        guesses.append(3)
        total_primes[1] -= 1
    for i in range(min_primes[2]):
        guesses.append(5)
        total_primes[2] -= 1
    if len(guesses) == 3:
        return guesses
    if min_primes[0] > 0:
        num_left = 3 - len(guesses)
        while min_primes[0] > num_left:
            guesses.append(4)
            if len(guesses) == 3:
                return guesses
            min_primes[0] -= 2
            num_left = 3 - len(guesses)
    while len(guesses) < 3:
        guesses.append(2)
    return guesses




def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        (r, n, m, k) = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        print 'Case #%d:' % (caseNum+1)
        for i in range(r):
            values = [int(x) for x in fileLines[index][:-1].split(' ')]
            index += 1
            answer = solve_small1(m, n, values)
            print "%s" % (''.join([str(x) for x in answer]))

if __name__ == '__main__':
    main(sys.argv[1])
