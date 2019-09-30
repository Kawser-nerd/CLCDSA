from random import randint
from math import factorial
def trysmall():
    fout = open('trysmall.txt', 'w')
    n = 10
    t = 362880
    adict = dict()
    for i in range(0, t):
        a = [str(x) for x in range(0, n)]
        for k in range(0, n):
            p = randint(0, n - 1)
            temp = a[p]
            a[p] = a[k]
            a[k] = temp
        stra = ''.join(a)
        if stra in adict:
            adict[stra]+=1
        else:
            adict[stra] = 1
    count = 0
    for key in adict:
        fout.write('%s %d\n' % (key, adict[key]))
        if adict[key] > t // factorial(n):
            count += 1
    fout.write('%d\n' % count)
    fout.close()

def calcsingle(n):
    fout = open('calcsingle.txt', 'w')
    for i in range(0, n):
        p = [0.0] * n
        p[i] = 1.0
        print(i)
        for k in range(0, n):
            pp = p.copy()
            for j in range(0, n):
                if j == k:
                    p[k] = pp[k] / n + (1 - pp[k]) / n
                else:
                    p[j] = pp[j] * (n - 1) / n + pp[k] / n
        fout.write(' '.join(str(x) for x in p))
        fout.write('\n')
        fout.flush()
    fout.close()
def run():
    fdict = open('calcsingle.txt', 'r')
    fin = open('C-small-attempt0.in', 'r')
    fout = open('out.txt', 'w')
    prob = []
    n = 1000
    for i in range(0, n):
        prob.append([float(x) for x in fdict.readline().split()])
    t = int(fin.readline())
    for casecount in range(1, t + 1):
        n = int(fin.readline())
        line = [int(x) for x in fin.readline().split()]
        judge = 1
        for i in range(0, n):
            judge *= prob[line[i]][i] * n
        fout.write('Case #%d: ' % casecount)
        if judge > 1.0:
            fout.write('BAD\n')
        else:
            fout.write('GOOD\n')
    fin.close()
    fout.close()

#trysmall()
run()
