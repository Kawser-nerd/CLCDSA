import string

t = int(input())

ansBase = 10**9 + 7


def isFull(word):
    diffs = set()
    for c in word:
        diffs.add(c)
        if len(diffs) > 1:
            return None
    return word[0]


def fact(x):
    res = 1
    for i in range(x):
        res *= i + 1
        res %= ansBase
    return res


def solve():
    symbs = string.ascii_lowercase
    n = int(input())
    words = input().split()
    assert len(words) == n
    weight = {}
    wasFull = set()

    words2 = []
    for w in words:
        if isFull(w):
            c = w[0]
            if c in wasFull:
                weight[c] += 1
            else:
                weight[c] = 1
                wasFull.add(c)
                words2.append(w)
        else:
            words2.append(w)
    words = words2
    #print(words)
    xAns = 1
    for key, value in weight.items():
        xAns *= fact(value)
        xAns %= ansBase
    
    g = {}
    prefs = {}
    sufs = {}
    fulls = {}
    isolates = {}
    for c in symbs:
        prefs[c] = []
        sufs[c] = []
        fulls[c] = []
        isolates[c] = []
    for w in words:
        g[w] = []
        if isFull(w):
            fulls[w[0]].append(w)
        else:
            pr = w[0]
            su = w[len(w) - 1]
            prefs[pr].append(w)
            sufs[su].append(w)
            l = 0
            while w[l] == w[0]:
                l += 1
            r = len(w) - 1
            while w[r] == w[len(w) - 1]:
                r -= 1
            last = ' '
            for i in range(l, r + 1):
                if last != w[i]:
                    isolates[w[i]].append(w)
                last = w[i]
    
    for c in symbs:
        '''
        print("###", c)
        print(prefs[c])
        print(sufs[c])
        print(fulls[c])
        print(isolates[c])
        '''
        
        if isolates[c]:
            if prefs[c] or sufs[c] or fulls[c] or len(isolates[c]) > 1:
                #print("ISOLATE", c)
                return 0
        else:
            if len(prefs[c]) > 1 or len(sufs[c]) > 1:
                return 0
            if sufs[c]:
                if fulls[c]:
                    g[sufs[c][0]].append(fulls[c][0])
                elif prefs[c]:
                    g[sufs[c][0]].append(prefs[c][0])
            if fulls[c]:
                if prefs[c]:
                    g[fulls[c][0]].append(prefs[c][0])

    for w in words:
        if len(g[w]) > 1:
            return 0

    noStarts = set()
    
    for w in words:
        was = set()
        curW = w[:]
        #print("#")
        while True:
            #print(curW, g[curW])
            if curW in was:
                return 0
            was.add(curW)
            if g[curW]:
                curW = g[curW][0]
                noStarts.add(curW)
            else:
                break
    numStarts = len(words) - len(noStarts)
    #print(numStarts, xAns, len(words))
    res = fact(numStarts)
    res *= xAns
    res %= ansBase
    return res
    

for i in range(t):
    res = solve()
    print("Case #{}: {}".format(i + 1, res))
