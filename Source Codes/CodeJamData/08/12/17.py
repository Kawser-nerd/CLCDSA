#!/usr/bin/python
''' Milkshakes
Google Code Jam 2008
Round 1A - Problem B
Grant Glouser <gglouser@gmail.com>
'''

import sys

def debug(*msg):
    DEBUG = not True
    if DEBUG:
        for x in msg[:-1]:
            print x,
        print msg[-1]

def read_int_line(f):
    return int(f.readline().rstrip())

def print_result(case_num, result):
    print 'Case #%d: %s' % (case_num, result)

def do_test_case(f, case_num):
    n = read_int_line(f)
    m = read_int_line(f)
    custs = []
    for i in range(m):
        like = f.readline().rstrip().split()
        like = [int(a) for a in like]
        t = like.pop(0)
        likes = [(like[2*j],like[2*j+1]) for j in range(t)]
        custs.append(likes)
    
    debug(n,m,custs)
    
    needs_malted = []
    last_len = -1
    while len(needs_malted) != last_len:
        last_len = len(needs_malted)
        # figure out what needs to be malted
        for cust in custs:
            if len(cust) == 1:
                flav,malt = cust[0]
                if malt == 1 and flav not in needs_malted:
                    needs_malted.append(flav)
        debug('needs malted:',needs_malted)
        
        # filter out incompatible flavor prefs
        new_custs = []
        for cust in custs:
            new_cust = [(flav,malt) for (flav,malt) in cust if (flav not in needs_malted) or (malt == 1)]
            if not new_cust:
                print_result(case_num, 'IMPOSSIBLE')
                return
            new_custs.append(new_cust)
        debug(new_custs)
        custs = new_custs
    debug('done')
    
    malts = []
    for i in range(n):
        if (i+1) in needs_malted:
            malts.append(1)
        else:
            malts.append(0)
    print_result(case_num, ' '.join([str(x) for x in malts]))

def main(input):
    f = file(input)
    n = read_int_line(f)
    for i in range(n):
        do_test_case(f, i+1)
    f.close()

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print 'usage: %s <input>' % sys.argv[0]
        sys.exit(1)
    main(sys.argv[1])
