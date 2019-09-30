import re, sys

def solve(v1, v2):
    v1.sort()
    v2.sort(reverse=True)
    prods = [a*b for a,b in zip(v1,v2)]
    sum =0
    for p in prods:
        sum+= p
    return sum
    
def parse_input():
    if len (sys.argv) < 2:
        print "Enter an input filename please"
        return
    inp = open (sys.argv[1])

    lines = [re.sub(r'[\n\r]','',l) for l in inp.readlines()]
    num_cases = int(lines[0])
    line_num = 1
    for case in xrange(num_cases):
        n = int(lines[line_num])
        v1 = [int(i) for i in lines[line_num+1].split()]
        v2 = [int(i) for i in lines[line_num+2].split()]
        line_num+=3
        soln = solve(v1, v2)
        print "Case #"+str(case+1)+":", soln

parse_input()