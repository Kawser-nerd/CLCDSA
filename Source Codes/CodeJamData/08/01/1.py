import sys
import re

def engine_usefulness(engine, queries, q):
    for k in range(q,len(queries)):
        if queries[k] == engine:
            return k - q
    return len(queries) - q


def switches(engines, queries):
    q = 0
    s = -1
    while q < len(queries):
        s += 1
        max_usefulness = 0
        for e in engines:
            this_usefulness = engine_usefulness(e, queries, q)
            if this_usefulness > max_usefulness:
                max_usefulness = this_usefulness
        q = q + max_usefulness
    return s



f = open('A-large.in', 'r')
##f = open('A-small-attempt1.in', 'r')

N_cases = int(re.search('\d+', f.readline()).group(0))
for case in range(N_cases):

    N_engines = int(re.search('\d+', f.readline()).group(0))

    engines = []
    for eng in range(N_engines):
        new_engine = f.readline()
        new_engine = new_engine[:-1]
        engines.append(new_engine)

    N_queries = int(re.search('\d+', f.readline()).group(0))
    if N_queries == 0:

        N_switches = 0

    else:

        queries = []
        for q in range(N_queries):
            new_query = f.readline()
            new_query = new_query[:-1]
            queries.append(new_query)

        N_switches = switches(engines, queries)

    print 'Case #%(a)d: %(b)d' % {'a':(case + 1), 'b':N_switches}

f.close()