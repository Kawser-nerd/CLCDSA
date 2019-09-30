def debug(*args):
	#print " ".join(str(arg) for arg in args)
	return

def memoizing(func):
    """Function decorator to cache a function's output."""
    memos = dict()
    def memoize(*args):
        if args in memos:
            return memos[args]
        res = func(*args)
        memos[args] = res
        return res
    return memoize
    
def run_process(args):
    res = solve_problem(*args)
    #print "Finished one"
    return res

def process_file(fin, fout):
    def get_problem():
        N = int(fin.readline().strip('\n'))
        W = [list(map(int, fin.readline().split(' '))) for n in range(N)]
        return (W,)
        
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

def wires_intersect(a,b):
    c = (a[0]-b[0], a[1]-b[1])
    return (c[0] < 0) ^ (c[1] < 0)
    
        
def solve_problem(W):
    L = list()
    intersections = 0
    for w in W:
        for l in L:
            if wires_intersect(w, l):
                intersections += 1
        L.append(w)
    return intersections
    
    
        
if __name__ == '__main__':
    from sys import argv
    process_file(open(argv[1]), open(argv[1].replace("in", "out"), "w"))
