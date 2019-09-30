import sys

def main(argv=None):
    if not argv:
        argv = sys.argv[1:]
    filename = argv[0] if argv else 'test.in'

    with open(filename) as f:
        numCases = int(f.readline())
        for caseNo in xrange(1, numCases+1):
            N, M = [int(tok) for tok in f.readline().split()]
            D = []
            L = []
            for i in xrange(N):
                D.append(f.readline().strip())
            for i in xrange(M):
                L.append(f.readline().strip())
            # print D, L
                
            answers = solve(D, L)
            print 'Case #{0}:'.format(caseNo),
            for word in answers:
                print word,
            print

def solve(D, L):
    answers = []

    lenDict = {}
    for word in D:
        lenDict.setdefault(len(word), []).append(word)
    # print lenDict

    D2 = []
    for word in D:
        d = {}
        for letter in L[0]:
            posns = [i for i, c in 



    for order in L:
        maxScore = -1
        bestWord = ''
        for length, words in lenDict.iteritems():
            # print words, order
            score, word = solveOne(words, order)

            if score > maxScore:
                maxScore = score
                bestWord = word
            if score == maxScore and D.index(word) < D.index(bestWord):
               bestWord = word

        answers.append(bestWord)
    return answers

def solveOne(D, order):
    if len(D) == 1:
        return 0, D[0]

    letter = order[0]
    pDict = {}
    for word in D:
        posns = [i for i, c in enumerate(word) if c == letter]
        pDict.setdefault(tuple(posns), []).append(word)
    
    # print order, pDict

    maxScore = -1
    bestWord = ''
    for posns, words in pDict.iteritems():
        score, word = solveOne(words, order[1:])
        if not posns and len(pDict) > 1:
            score += 1

        if score > maxScore:
            maxScore = score
            bestWord = word
            
        if score == maxScore and D.index(word) < D.index(bestWord):
            bestWord = word

    return maxScore, bestWord













    
if __name__ == '__main__':
    main()
