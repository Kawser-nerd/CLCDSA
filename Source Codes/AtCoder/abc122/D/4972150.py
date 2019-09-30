import itertools
N = int(input())
AGCs = [
    'AGC',
    'GAC',
    'ACG',
    'AGAC',
    'AGGC',
    'AGTC',
    'ACGC',
    'ATGC',
]
seq = ["A", "G", "C", "T"]
from collections import Counter
memo = Counter()

count = 0
new_S = []
def memo_saiki(n, start_memo):
    if n==1:
        print(4)
        exit()
    if n==2:
        print(16)
        exit()
    memo = start_memo
    new_memo = Counter()
    for _ in range(n-3):
        for k, v in memo.items():
            for char in 'AGCT':
                target = k+char
                if any([agc in target for agc in AGCs]):
                    continue
                new_memo.update({target[-3:]: v})
        memo = new_memo
        new_memo = Counter()
    print(sum([v for v in memo.values()]) % (10**9 + 7))

def saiki(n=6):
    S = ['']
    new_S = []
    memo = {}
    for _ in range(n):
        for i, s in enumerate(S):
            for c in 'AGCT':
                memo[s[-3:]] = 1
                hoge = s[-3:] + c
                if any([agc in hoge for agc in AGCs]):
                    continue
                new_S.append(hoge)
        S = new_S
        new_S = []
    #S = new_S.copy()
    return S
memo_saiki(n=N, start_memo = Counter(saiki(3)))