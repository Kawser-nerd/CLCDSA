from sys import stderr, stdin

dict = [z for z in open("garbled_email_dictionary.txt").read().split("\n") if len(z)]

def enstarifyword(word, stars, n):
    return "".join(["*" if (z in stars) else word[z] for z in xrange(n)]) 

expectedFirstLetter = "_"
words = set([])
for d in dict:
    if d[0] != expectedFirstLetter:
        expectedFirstLetter = d[0]
        print >>stderr, expectedFirstLetter, len(words)
    words.add(d)
    n = len(d)
    for i in xrange(n):
        words.add(enstarifyword(d,[i],n))
    for i in xrange(n):
        for j in xrange(i+5,n):
            words.add(enstarifyword(d,[i,j],n))

print >>stderr, "Download input file now and press enter!"
stdin.readline()
        
def parse(inFile):
    return inFile.readline()

def solve(line):
    n = len(line)
    solution = [[0 if (a == 0) else n * (1000000) for b in xrange(5)] for a in xrange(n + 1)]
    for a in xrange(1, n + 1):
        for lngth in xrange(1, min(a, 10) + 1):
            garble = line[a - lngth:a]
            possstars = [[]] + [[i] for i in xrange(lngth)] + [[i,j] for i in xrange(lngth) for j in xrange(i+5,lngth)]
            possstars = [z for z in possstars if enstarifyword(garble, z, lngth) in words]
            for j1 in xrange(5):
                for j2 in xrange(5):
                    if j2 <= j1 + lngth: # linguo is dense sometimes. at least arsenal are 1-0 up.
                        if solution[a - lngth][j1] <= n:
                            solns = [p for p in possstars if (p == []) or ((min(p) + j1 >= 4) and (max(p) + j2 <= lngth - 1))]
                            if len(solns) > 0:
                                solution[a][j2] = min(solution[a][j2], solution[a - lngth][j1] + min([len(z) for z in solns]))
        if False:
            for w in xrange(6):
                if solution[a][w] <= n:
                    print a, w, solution[a][w]
    return min([z for z in solution[-1] if z != -1])

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(parse, solve, "/Users/lpebody/gcj/2013_1b/c", "C").run()

