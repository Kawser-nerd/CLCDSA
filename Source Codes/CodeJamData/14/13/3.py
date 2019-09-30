from pylab import *
from sklearn import svm
from sklearn.feature_selection import SelectKBest, f_regression
from sklearn.pipeline import Pipeline

def gen(n):
    bad = randint(2)%2==1
    p = range(n)
    for i in range(n):
        if bad:
            j = randint(n)
        else:
            j = randint(n-i)+i
        t = p[i]
        p[i]=p[j]
        p[j]=t
    return (bad, p)

def g(p):
    """
    s=0
    for i in range(len(p)):
        for j in range(i):
            if p[i]>p[j]:
                s+=1
    yield s
    s=0
    for i in range(len(p)):
        j = p[i]
        cnt = 1
        while j!=i:
            j = p[j]
            cnt += 1
        s+=cnt
    yield s
    for i in range(len(p)):
        if i%100==0:
            yield p[i]
    """
    k = 5
    l = n/k
    for i in range(k):
        for j in range(k):
            s = 0
            for t in range(l):
                if (j+1)*l>p[i*l+t]>=j*l:
                    s += 1
            yield s

def f(p):
    return list(g(p))

n = 1000
m = 2000

anova_filter = SelectKBest(f_regression, k='all')
clf = svm.SVC(kernel='linear')
anova_svm = Pipeline([('anova', anova_filter), ('svm', clf)])

def train():
    train = [gen(n) for _ in range(m)]
    X = array([f(p) for _, p in train])
    Y = array([1. if bad else 0. for bad, _ in train])
    anova_svm.fit(X, Y)

train()
"""
test = [gen(n) for _ in range(m)] 
X = array([f(p) for _, p in test])
Y = anova_svm.predict(X)
wrong = sum(1 if (test[i][0] and Y[i]==0. or not test[i][0] and Y[i]==1.) else 0 for i in range(len(test)))
"""

import sys
tnum = input()
for tcou in range(tnum):
    n = input()
    arr = [int(x) for x in raw_input().split()]
    y = anova_svm.predict(array([f(arr)]))
    print 'Case #{}: {}'.format(tcou+1, 'BAD' if y>0.5 else 'GOOD')
