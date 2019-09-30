import os.path, glob
PROBLEM = os.path.basename(__file__)[0].upper()
DL_DIR = os.path.join(os.environ['USERPROFILE'], 'Downloads', PROBLEM)
if os.path.exists(DL_DIR + '-large.in'):
    INP_PATH = DL_DIR + '-large.in'
    OUT_PATH = DL_DIR + '-large.ot'
else:
    inputs = glob.glob(DL_DIR + '-small-attempt[0-9].in')
    maxnum = -1
    for inp_fn in inputs:
        if int(inp_fn[-4]) > maxnum: maxnum = int(inp_fn[-4])
    if maxnum > -1:
        INP_PATH = DL_DIR + '-small-attempt' + str(maxnum) + '.in'
        OUT_PATH = DL_DIR + '-small-attempt' + str(maxnum) + '.ot'
    else:
        INP_PATH = os.path.join('..', 'data', PROBLEM + '.in')
        OUT_PATH = os.path.join('..', 'data', PROBLEM + '.ot')

in_file = open(INP_PATH)
out_file = open(OUT_PATH, 'w')

def pp(s):
    out_file.write(s + '\n')
    print s


from gmpy2 import mpfr, sqrt

NUM_CASES = int(in_file.readline().strip())
for case in range(1, NUM_CASES + 1):
    soln = ''
    dat = in_file.readline().strip().split()
    d = mpfr(dat[0])
    n = int(dat[1])
    a = int(dat[2])
    
    this_time, this_pos = map(mpfr, in_file.readline().strip().split())
    last_time, last_pos = this_time, this_pos
    car_time = 0.0
    inp_count = 1
    while this_pos < d:
        last_time, last_pos = this_time, this_pos
        dat = in_file.readline().strip().split()
        this_time, this_pos = map(mpfr, dat)
        inp_count += 1
        if this_pos >= d:
            spd = (this_pos - last_pos) / (this_time - last_time)
            car_time = (d - last_pos) / spd + last_time
            break
    while inp_count < n:
        in_file.readline()
        inp_count += 1
    a_data = map(mpfr, in_file.readline().strip().split())
    pp('Case #' + str(case) + ':')
    for acc in a_data:
        opt_time = sqrt(2.0 * d / acc)
#        print opt_time, car_time
        pp(str(max(opt_time, car_time)))
    
    
out_file.close()
in_file.close()
