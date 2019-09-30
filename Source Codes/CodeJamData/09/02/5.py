import re
import sys
sys.setrecursionlimit(100000)

'''
FINALLY!!!
You know, google, you really shouldn't put cryptic order-related conditions in the problem statement.
It took me 4 times as long to find a stupid north-south-whatever bug than to write the actual algorithm.
:(
'''

def memoize(fun):
    '''
    A Decorator.
    Memoizes a function.
    Be careful, now.
    '''
    memoized = {}
    def memo(*args, **kwargs):
        if not kwargs:
            key = args
        else:
            key = (args,str(kwargs))
        if not key in memoized:
            memoized[key] = fun(*args, **kwargs)
        return memoized[key]
    return memo

elevation = None

# North, West, East, South, reversed
coords = [
    [0,-1,  1],
    [-1,0, 2],
    [1,0,  4],
    [0,1, 3],
][::-1]
print coords

@memoize
def get_sink(x, y, test_case):
    best_dx, best_dy = 0, 0
    cur_dir = 0
    for dx,dy,dir in coords:
        if x+dx >= 0 and x+dx < len(elevation[0]) and y+dy>=0 and y+dy< len(elevation):
            if elevation[y+dy][x+dx] < elevation[y+best_dy][x+best_dx]:
                best_dx, best_dy = dx, dy
                cur_dir = dir
            elif elevation[y+dy][x+dx] == elevation[y+best_dy][x+best_dx] and cur_dir != 0:
                best_dx, best_dy = dx, dy
                cur_dir = dir
    if cur_dir == 0:
        return (x,y)
    return get_sink(x+best_dx, y+best_dy, test_case)

text = [line.strip("\n") for line in open("B.in","rt").readlines()]
outfile = open("B.out","wt")

tests = int(text[0])
print tests
offset = 1
for test in range(1, tests+1):
    print text[offset]
    h, w = [int(_) for _ in text[offset].split(" ")]
    print(h,w)
    offset += 1
    elevation = [[int(_) for _ in line.split(" ")] for line in text[offset:offset+h]]
    #print elevation
    sink = [[get_sink(x,y, test) for x in range(0, len(elevation[0]))] for y in range(len(elevation))]
    #print sink
    sinks = {}
    sinks_letters = []
    for line in sink:
        sinks_letters.append([])
        for item in line:
            if not item in sinks:
                assert("a" <= chr(ord("a") + len(sinks)) <= "z")
                sinks[item] = chr(ord("a") + len(sinks))
            sinks_letters[-1].append(sinks[item])
    print "Case #%s:" % test
    outfile.write("Case #%s:\n" % test)
    for line in sinks_letters:
        print " ".join(line)
        outfile.write(" ".join(line) + "\n")
    offset += h

