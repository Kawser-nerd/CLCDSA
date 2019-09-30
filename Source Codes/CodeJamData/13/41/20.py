from collections import Counter

#def solve(N, M, O, E, P):
def solve(N, M, P):

    ori = 0
    for p in P:
        dis = p[1] - p[0]
        #ori += (p[0] + p[1]) * dis / 2
        start = N
        end = N + 1 - dis
        ori += p[2] * (start+end) * dis / 2

    times = [p[0] for p in P] + [p[1] for p in P]
    times = list(set(times))
    times.sort()
    pool = {}
    spent = 0
    for t in times:
        up = 0
        for p in P:
            # UP
            if p[0] == t:
                up += p[2]
        #Down
        down = 0
        for p in P:
            if p[1] == t:
                down += p[2]


        #print t, up, down
        if up > down: 
            up = up - down
            down = 0
        elif up <= down:
            down = down - up
            up = 0
        #print t, up, down

        
        #print '======='
        #print 'stage', t
        #print 'up', up
        #print 'down', down
        #print '======='

        #print '==='
        #print pool, spent

        if up > 0:
            pool[t] = up
        while down > 0:
            #print 'downing'
            #print pool
            #print sorted(pool)
            #print pool
            index = sorted(pool)[-1]
            if down >= pool[index]: 

                dis = t - index
                start = N 
                end = N + 1 - dis
                spent += pool[index] * (start + end) * dis / 2

                down -= pool[index]
                del pool[index]
            else:
                dis = t - index
                start = N 
                end = N + 1 - dis
                spent += down * (start + end) * dis / 2

                pool[index] -= down
                down = 0
        
        #print pool, spent
        #print '==='
    
    #print pool
    #print ori
    #print spent 
    #print ori - spent

    return (ori - spent) % 1000002013

if __name__ == '__main__':

    import sys
    
    input_file = sys.argv[1]
    output_file = input_file[:].replace('.in', '.out')


    f_in = open(input_file, 'r')
    f_out = open(output_file, 'w')

    T, = [int(x) for x in f_in.readline().split()]

    for case in range(1, T+1):
        print 
        print '====================='
        print '    ' + str(case)
        print '====================='

        N, M = [int(x) for x in f_in.readline().split()]
        #O = [0 for i in range(M)]
        #E = [0 for i in range(M)]
        #P = [0 for i in range(M)]
        #for i in range(M):
        #    O[i], E[i], P[i] = [int(x) for x in f_in.readline().split()]
        P = []
        for i in range(M):
            P.append([int(x) for x in f_in.readline().split()])


        # Solve
        ans = solve(N, M, P)

        ## Output
        f_out.write('Case #%d: %s\n' % (case, ans))

        

