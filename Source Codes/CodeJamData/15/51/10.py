import sys
from multiprocessing import Pool

# Add git repository with helpers to path
# The repo is publicly available at git@github.com:marcelka/cocoli.git
sys.path.append("/home/marcelka/projects/cocoli/")

def run(pool=None): # {{{
    inp=sys.argv[1]
    outp="%s.out" % inp.split(".")[0]

    with open(inp, 'r') as _file, open(outp, 'w') as out:
        _cases = int(_file.readline())
        arguments = []
        for _case in range(_cases):
            N, D = tuple([int(x) for x in _file.readline().split(" ")])
            S0, As, Cs, Rs = tuple([int(x) for x in _file.readline().split(" ")])
            M0, Am, Cm, Rm = tuple([int(x) for x in _file.readline().split(" ")])
            arguments.append((_case + 1, (N, D, S0, As, Cs, Rs, M0, Am, Cm, Rm)))

        if pool == None:
            results = list(map(solve_wrapper, arguments))
        else:
            results = sorted(
                list(pool.imap_unordered(solve_wrapper, arguments)),
                key=lambda r: r[0])
        
        for _case, result in results:
            out.write("Case #%s: %s\n" % (_case, result))

def solve_wrapper(args):
    case_no, _args = args
    print("Solving case #%s" %(case_no))
    return (case_no, solve(*_args))
# }}}

def count(tree, mid, mins, maxs):
    result = 0
    for eid, es in tree[mid]:
        if mins <= es and es <= maxs:
            result += 1 + count(tree, eid, mins, maxs)
    return result
    
def tree(N, S0, As, Cs, Rs, M0, Am, Cm, Rm):
    result = dict((i, []) for i in range(N))
    Si, Mi = (S0, M0)
    for i in range(1, N):
        Si = (Si * As + Cs) % Rs
        Mi = (Mi * Am + Cm) % Rm
        result[Mi % i].append((i, Si))
    return result


def solve(N, D, S0, As, Cs, Rs, M0, Am, Cm, Rm):
    company = tree(N, S0, As, Cs, Rs, M0, Am, Cm, Rm)
    possible_min = max(0, S0 - D)
    possible_max = S0 + D
    left = 0
    for min_salary in range(possible_min, S0+1):
        left = max(left, count(company, 0, min_salary, min_salary + D))
    return left + 1

import sys
sys.setrecursionlimit(10000)
run()
#run(Pool(4))
