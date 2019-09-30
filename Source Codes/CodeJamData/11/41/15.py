infile = open('airport_walk.in')
outfile = open('airport_walk.out', 'w')

T = int(infile.readline().strip())

for t in xrange(T):
    X, S, R, runtime, N = [int(s) for s in infile.readline().strip().split()]
    run_bonus = R - S
    
    speeds, lengths = [], []

    walkways = []
    for i in xrange(N):
        B, E, w = [int(s) for s in infile.readline().strip().split()]
        walkways.append((w + S, E - B))

    sum_lens = sum(w[1] for w in walkways)
    walkways.append((S, X - sum_lens))
    walkways = sorted(walkways, key=lambda w: w[0])

    answer = 0.0
    for speed, distance in walkways:
        cur_runtime = min(distance/float(speed + run_bonus), float(runtime))
        runtime -= cur_runtime
        answer += cur_runtime + ((distance - (speed + run_bonus) * cur_runtime)
                                 / float(speed))
        
    outfile.write('Case #%d: %.9f\n' % (t + 1, answer))
