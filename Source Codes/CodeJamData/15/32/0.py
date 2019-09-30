from fractions import Fraction

def trie(K, keyboard, L, word):
    x = [[0 for i in xrange(L + 1)] for j in xrange(L + 1)]
    for key in keyboard:
        for p in xrange(L + 1):
            newword = word[:p] + key
            while newword != word[:len(newword)]:
                newword = newword[1:]
            x[p][len(newword)] += Fraction(1, K)
    return [{j:x[i][j] for j in xrange(L+1) if x[i][j]>0} for i in xrange(L+1)]

def score(K, keyboard, L, word, S):
    tr = trie(K, keyboard, L, word)
    score = [[0 for i in xrange(S + 1)] for j in xrange(L + 1)]
    score[0][0] = 1
    for p in xrange(S):
        newscore = [[0 for i in xrange(S + 1)] for j in xrange(L + 1)]
        for i in xrange(S + 1):
            for j in xrange(L + 1):
                if score[j][i] > 0:
                    for newj in tr[j]:
                        newi = i + (1 if (newj == L) else 0)
                        newscore[newj][newi] += tr[j][newj] * score[j][i]
        score = newscore
    score = [sum(s[i] for s in score) for i in xrange(S+1)]
    maxscore = max(i for i in xrange(S+1) if score[i] > 0)
    avgscore = sum(score[i]*i for i in xrange(S+1))
    return float(maxscore-avgscore)

from sys import stdin

for case in xrange(1,1+int(stdin.readline())):
    (K, L, S) = tuple(int(z) for z in stdin.readline().split())
    keyboard = stdin.readline().strip()
    word = stdin.readline().strip()
    print "Case #%d: %.9f" % (case, score(K, keyboard, L, word, S))
