t = int(raw_input())

memoriz = {}

def solve(p, cells, start, end):
    min = None
    if memoriz.has_key((start, end)):
        return memoriz[(start, end)]
    for i in cells:
        if i <= end and i >= start:
            if min == None or solve(p, cells, start, i-1) + solve(p, cells, i+1, end) + end - start < min:
                min = solve(p, cells, start, i-1) + solve(p, cells, i+1, end) + end - start
    if min == None: #no prisoner to be released between start and end
        memoriz[(start, end)] = 0
        return 0
    else:
        memoriz[(start, end)] = min
        return min

for i in range(t):
    p, q = map(int, raw_input().split())
    cells = list(map(int, raw_input().split()))
    memoriz = {}
    print "Case #%d: %d"%(i+1, solve(p, cells, 1, p))
