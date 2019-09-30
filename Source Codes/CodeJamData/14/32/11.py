alphabet = "abcdefghijklmnopqrstuvwxyz"
MOD = 1000000007

import math,itertools

def compress(s):
    assert len(s) > 0
    s2 = s[0]
    for c in s:
        if c != s2[-1]:
            s2 += c
    return s2

def solve2(testnum):
    n = int(input())
    l = input().split()
    assert len(l) == n
    out = 0
    for p in itertools.permutations(l):
        s = "".join(p)
        used = set()
        prev = ''
        works = True
        for c in s:
            if c != prev:
                if c in used:
                    works = False
                    break
                else:
                    used.add(c)
                    prev = c
        if works: out += 1
    out %= MOD
    print("Case #%d: %d"%(testnum,out))

def solve(testnum):
    n = int(input())
    l = input().split()
    assert len(l) == n
    
    numpref = dict([(c,0) for c in alphabet])
    numsuf = dict([(c,0) for c in alphabet])
    internal = dict([(c,0) for c in alphabet])
    single = dict([(c,0) for c in alphabet])
    l2 = [compress(s) for s in l]
    for s in l2:
        if len(s) == 1: single[s] += 1
        else:
            numpref[s[0]] += 1
            numsuf[s[-1]] += 1
        if len(s) > 2:
            for c in s[1:-1]:
                internal[c] += 1
    #print("Scored")
    for c in alphabet:
        if internal[c] > 0 and \
           (numpref[c] > 0 or numsuf[c] > 0 or \
            internal[c] > 1 or single[c] > 0):
            #print("A")
            print("Case #%d: 0"%testnum)
            return
        if numpref[c] > 1 or numsuf[c] > 1:
            #print("B")
            print("Case #%d: 0"%testnum)
            return
    #print("Checked")
    used = set([])
    def construct(c):
        #print(used)
        assert numsuf[c] == 0
        out = 1
        while numpref[c] > 0:
            out *= math.factorial(single[c])
            used.add(c)
            #out %= MOD
            for s in l2:
                if s[0] == s[-1]: continue
                if c == s[0]:
                    c = s[-1]
                    break
            if c in used: return 0
        out *= math.factorial(single[c])
        used.add(c)
        out %= MOD
        #print(used,c)
        return out
    out = 1
    num = 0
    for c in alphabet:
        if c in used: continue
        if numsuf[c] == 0 and (numpref[c] > 0 or single[c] > 0):
            num += 1
            #print("Con",c)
            out *= construct(c)
            #out %= MOD
    #print("Const")
    for c in alphabet:
        if c not in used and \
           (numsuf[c] > 0 or numpref[c] > 0 or single[c] > 0):
            #print("C")
            #print(c,used,numsuf,numpref,single)
            print("Case #%d: 0"%testnum)
            return
    #print("Checked again")
    #print(num)
    out *= math.factorial(num)
    out %= MOD
    print("Case #%d: %d"%(testnum,out))

for i in range(int(input())): solve(i+1)
