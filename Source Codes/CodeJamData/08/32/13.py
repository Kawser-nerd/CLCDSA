import sys, math

def ugly(num):
    return True if num % 2 == 0 or num % 3 == 0 or num % 5 == 0 or num % 7 == 0 else False
    
def solve(val, str, rest):
    if len(rest) == 0 and len(str) == 0:
        #print '%d is %s' % (val, ugly(val))
        return 1 if ugly(val) else 0
    if mem.has_key(val) and mem[val].has_key(str) and mem[val][str].has_key(rest):
        #print '%d, %s, %s = %d' % (val, str, rest, mem[val][str][rest])
        return mem[val][str][rest]
    
    #print '%d, %s, %s ...' % (val, str, rest)
    count = 0
    if len(str) > 0:
        digits = int(str)
        count += solve(val + digits, '', rest)
        if totallen > len(rest) + len(str): count += solve(val - digits, '', rest)
        
    if len(rest) > 0:
        count += solve(val, str + rest[0], rest[1:])
    
    if not mem.has_key(val): mem[val] = {}
    if not mem[val].has_key(str): mem[val][str] = {}
    mem[val][str][rest] = count
    
    return count
    
def handle(infile, outfile):
    number = infile.readline().strip()
    
    global totallen, mem
    totallen = len(number)
    mem = {}
    if len(number) > 1:
        count = solve(0, number[0], number[1:])
    else:
        count = 1 if ugly(int(number)) else 0
    outfile.write(' %d' % count)

if len(sys.argv) != 2: exit()
infile = file(sys.argv[1], 'r')
outfile = file(sys.argv[1] + '.out', 'w')

count = int(infile.readline())
for i in range(count):
    print 'Case #%d' % (i + 1)
    outfile.write('Case #%d:' % (i + 1))
    result = handle(infile, outfile)
    outfile.write('\n')
