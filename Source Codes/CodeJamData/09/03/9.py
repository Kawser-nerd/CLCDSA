# -*- coding: utf-8 -*-

from pprint import pprint

VERBOSE = True
VERBOSE = False

PHRASE = "welcome to code jam"
MODULO = 10000

PHRASE_LEN = len(PHRASE)

def solve(task):
    # Dynamic programming. We search for every suffix of the phrase
    # from every initial position. count[pos][phrase] is the count of
    # phrase's in task[pos:]
    task_len = len(task)
    count = [ {"" : 1 } for l in range(0, task_len+1) ]
    for suffix_len in range(1, PHRASE_LEN+1):
        suffix = PHRASE[-suffix_len:]
        for pos in range(task_len - 1, -1, -1):
            cnt = count[pos+1].get(suffix, 0)
            if suffix[0] == task[pos]:
                cnt += count[pos+1].get(suffix[1:], 0)
            count[pos][suffix] = cnt % MODULO
    return count[0][PHRASE]

if __name__ == "__main__":
    import sys
    if not len(sys.argv) == 2:
        raise Exception("Give input as parameter")

    input = open(sys.argv[1])

    tasks_count = int(input.readline())

    for task_no in xrange(0, tasks_count):
        task = input.readline().strip()
        r = solve(task)
        print "Case #%d: %04d" % (task_no + 1, r)
