from math import log, ceil



def solve_problem(L, P, C):
    intervals = int(ceil(log((P+L-1) / L, C)))
    tests = 0
    while intervals > 1:
        tests += 1
        intervals = (intervals + 1) / 2

    return tests
    
def run_process(args):
    return solve_problem(*args)

def process_file(fin, fout):
    def get_problem():
        return map(int, fin.readline().split(' '))
        
    numLines = int(fin.readline())
    problem_list = [get_problem() for i in range(numLines)]
    
    if False:
        from multiprocessing import Pool
        p = Pool(8)
        solution_list = p.map(run_process, problem_list)
    else:
        solution_list = map(run_process, problem_list)
    for i, s in enumerate(solution_list):
        fout.write("Case #%s: %s\n" % (i + 1, s))
        
if __name__ == '__main__':
    from sys import argv
    process_file(open(argv[1]), open(argv[1].replace("in", "out"), "w"))
