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
    return solve_problem(*args)

def process_file(fin, fout):
    def get_problem():
        ff, ft, tf, tt = [False, False], [False, True], [True, False], [True, True]
        hex_unpack = [ 
            ff + ff, ff + ft, ff + tf, ff + tt,
            ft + ff, ft + ft, ft + tf, ft + tt,
            tf + ff, tf + ft, tf + tf, tf + tt,
            tt + ff, tt + ft, tt + tf, tt + tt,    
        ]
        
        M, N = map(int, fin.readline().split(' '))
        G = [list(fin.readline().strip('\n')) for m in xrange(M)]
        assert all(len(g) == N/4 for g in G)
        G = [sum((hex_unpack[int(c, 16)] for c in g), []) for g in G]
        
                #Increase 64fold for stress test
        #G = sum(map(lambda i:[list(g * 8) for g in G], range(8)), [])
        #M *= 8
        #N *= 8
        
        return (M, N, G)
        
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

def board_size(M, N, G, x, y):
    base = G[x][y]
    if base == None: return 0
    max_size = min(M-x, N-y)
    
    for i in range(1, max_size):
        for a in range(i+1):
            if not (base == G[x+i][y+a] == G[x+a][y+i]):
                return i
    return max_size
    
def remove_board(G, S, I, J, W):
    for x in xrange(max(0, I-W), I):
        for y in xrange(max(0, J-W), J):
            if S[x][y] > max(I-x, J-y):
                S[x][y] = max(I-x, J-y)
        for y in xrange(W):
            if S[x][J+y] > I-x:
                S[x][J+y] = I-x
    for x in xrange(W):
        for y in xrange(max(0, J-W), J):
            if S[I+x][y] > J-y:
                S[I+x][y] = J-y
        for y in xrange(W):
            G[I+x][J+y] = None
            S[I+x][J+y] = 0
    
                
        
        
def solve_problem(M, N, G):
    # Simplify the size-checking operation - change markings from white/black to odd-based checkers/even-based checkers
    for i in range(M):
        for j in range(N):
            if (i + j) % 2 == 1:
                G[i][j] = not G[i][j]
    S = [[0 for i in xrange(N)] for j in xrange(M)] #holds the max possible board size originating each point
    for x in range(M):
        for y in range(N):
            S[x][y] = board_size(M, N, G, x, y)
    max_size = max(max(S[r]) for r in xrange(M))
    
    removed_boards = list()
    while max_size > 0:
        print max_size
        removed = 0
        for i in range(M):
            for j in range(N):
                if S[i][j] == max_size:
                    remove_board(G, S, i, j, max_size)
                    removed += 1
        removed_boards.append((max_size, removed))
        print removed_boards        
        max_size = max(max(S[r]) for r in xrange(M))
    return str(len(removed_boards)) + "\n" + "\n".join("%s %s" % b for b in removed_boards)
    

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
if __name__ == '__main__':
    from sys import argv
    process_file(open(argv[1]), open(argv[1].replace("in", "out"), "w"))
