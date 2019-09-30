#!/usr/bin/env python
from __future__ import unicode_literals
import codecs
import collections
import itertools
import sys


MODULO = 1000000007
FACT_ARRAY = [1, 1]
def fact(n):
    if n >= len(FACT_ARRAY):
        curr_n = len(FACT_ARRAY)
        for c in xrange(curr_n, n+1):
            FACT_ARRAY.append((FACT_ARRAY[-1]*c) % MODULO)
    return FACT_ARRAY[n]

def get_answer_for_combs(combs):
    result = 1
    for num in combs:
        result = (result * fact(num)) % MODULO
    return result

def get_result(strs):
    # print
    # print("Starting new case: {}".format(strs))
    single_letter_strings = collections.defaultdict(int)
    new_strs = set()
    starts = {}
    ends = {}
    for s in strs:
        if len(set(s)) == 1:
            single_letter_strings[s[0]] += 1
        else:
            if s[0] in starts:
                return 0
            starts[s[0]] = s
            if s[-1] in ends:
                return 0
            ends[s[-1]] = s
            new_strs.add(s)
    single_strs = set(single_letter_strings.iterkeys())

    frags = []
    while new_strs:
        curr_frag = collections.deque()
        curr = new_strs.pop()
        # print("seeding fragment with {}".format(curr))
        curr_frag.append(curr)
        while 1:
            # try to extend forward
            last_car = curr_frag[-1]
            if last_car[-1] in single_strs:
                single_strs.remove(last_car[-1])
                # print("extended frag tail with single letter: {}".format(last_car[-1]))
            if last_car[-1] in starts:
                # continue the chain
                next_car = starts[last_car[-1]]
                if next_car not in new_strs:
                    return 0
                new_strs.remove(next_car)
                curr_frag.append(next_car)
                # print("extended frag tail with new car: {}".format(next_car))
            else:
                # print("couldn't extend tail")
                break

        while 1:
            # try to extend forward
            first_car = curr_frag[0]
            if first_car[0] in single_strs:
                single_strs.remove(first_car[0])
                # print("extended frag head with single letter: {}".format(first_car[0]))
            if first_car[0] in ends:
                # continue the chain
                prev_car = ends[first_car[0]]
                if prev_car not in new_strs:
                    return 0
                new_strs.remove(prev_car)
                curr_frag.appendleft(prev_car)
                # print("extended frag head with new car: {}".format(prev_car))
            else:
                # print("couldn't extend head")
                break

        frags.append(''.join(curr_frag))

    check_set = set()
    for c, g in itertools.groupby(''.join(frags)):
        if c in check_set:
            return 0
        check_set.add(c)

    free_combs = single_letter_strings.values()
    free_combs.append(len(frags)+len(single_strs))
    # print "free combs: {}".format(free_combs)
    return get_answer_for_combs(free_combs)


def main(argv=sys.argv):
    assert len(argv) == 3, "argv was not of length 3: {}".format(argv)
    infile = argv[1]
    outfile = argv[2]
    with codecs.open(infile, 'r', 'utf8') as fin,\
            codecs.open(outfile, 'w', 'utf8') as fout:
        T = int(fin.readline().strip())
        for case_num in xrange(1, T+1):
            N = int(fin.readline().strip())
            strs = fin.readline().strip().split()
            assert len(strs) == N, case_num
            result = get_result(strs)
            fout.write('Case #{}: {}\n'.format(case_num, result))
    return 0

if __name__ == "__main__":
    status = main()
    sys.exit(status)
