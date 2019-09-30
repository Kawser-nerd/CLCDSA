#!/usr/bin/python
import os, sys, math

#global best_matrix

def max_energy(max_e, e, r, values, i):
    #global best_matrix
    if (i == (len(values) - 1)):
        return (e*values[i], 0)
    #if (e, i) in best_matrix:
    #    return best_matrix[(e, i)]
    # try all E values, good enough for small
    best = 0
    best_index = -1
    # only a few things make sense (i think?):
    # - 0 (or if we're going to be capped, that)
    # - all
    possible_energies = [0, e]
    if (e+r > max_e):
        possible_energies[0] = min(e, e+r-max_e)
    next_highest = 1
    while (i + next_highest) < len(values) and values[i+next_highest] < values[i]:
        next_highest += 1
    # next higher one is next_highest away
    if (i + next_highest) == len(values):
        # this is the highest one left. spend it all!
        possible_energies = [e]
    else:
        # leave us at max for that one
        #possible_energies[0] = min(e, max(possible_energies[0], (e + next_highest * r) - max_e))
        possible_energies = [min(e, max(possible_energies[0], (e + next_highest * r) - max_e))]

    #for energy_to_use in range(0, e+1):
    energy_to_use = possible_energies[0]
    #for energy_to_use in possible_energies:
    energy_for_next_step = min(e-energy_to_use+r, max_e)
    return (energy_to_use*values[i], energy_for_next_step)
    #    total_energy = energy_to_use*values[i] + max_energy(max_e, min(e-energy_to_use+r, max_e), r, values, i+1)
    #    if total_energy > best:
    #        best = total_energy
    #        best_index = energy_to_use

    #print "e = %d i = %d returning %d (best_index %d)" % (e, i, best, best_index)
    #best_matrix[(e, i)] = best
    #return best

def solve(e, r, values):
    global best_matrix
    best_matrix = {}
    # no longer dynamic, just returns new state
    best = 0
    max_e = e
    for i in range(len(values)):
        (new_energy, e) = max_energy(max_e, e, r, values, i)
        best += new_energy

    return best

def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        (e, r, n) = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        values = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        #answer = solve_fast(r, t)
        answer = solve(e, r, values)
        #print caseStr
        print "Case #%d: %d" % (caseNum + 1, answer)

if __name__ == '__main__':
    main(sys.argv[1])
