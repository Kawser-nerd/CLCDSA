#!/usr/bin/env python

import re
import sys

class Memoize:
    def __init__(self,function):
        self._cache = {}
        self._callable = function
            
    def __call__(self, *args, **kwds):
        cache = self._cache
        key = self._getKey(*args,**kwds)
        try: return cache[key]
        except KeyError:
            cachedValue = cache[key] = self._callable(*args,**kwds)
            return cachedValue
    
    def _getKey(self,*args,**kwds):
        return kwds and (args, ImmutableDict(kwds)) or args    

def consistent(w, guess, alphabet):
    if len(guess) != len(w):
        return False
    for i in range(len(guess)):
        c1, c2 = guess[i], w[i]
        if c1 == '_':
            if c2 not in alphabet:
                return False
        elif c1 != c2:
            return False
    return True

def reveal(letter, guess, chosen):
    s = []
    for i in range(len(guess)):
        if letter == chosen[i]:
            s.append(letter)
        else:
            s.append(guess[i])
    return ''.join(s)

#@Memoize
def error_count(words, alphabet, chosen, guess=None):
    if guess is None:
        print "-------------------------"
        print words
        guess = "_" * len(chosen)
        #import pdb; pdb.set_trace()
    if "_" not in guess:
        return 0
    for i, a in enumerate(alphabet):
        for w in words:
            if a in w and consistent(w, guess, alphabet):
                # we're going to guess a
                print "guessing %s %s for %s because it matches %s (alphabet %s)" % (a, guess, chosen, w, alphabet)
                new_guess = reveal(a, guess, chosen)
                if new_guess == guess:
                    print "XXX"
                    return 1 + error_count(words, alphabet[i+1:], chosen, new_guess)
                return error_count(words, alphabet[i+1:], chosen, new_guess)

def do_test(words, alphabet):
    counts = [(w, error_count(words, alphabet, w)) for w in words]
    print counts
    best_score = max(t[1] for t in counts)
    for (w,c) in counts:
        if best_score == c:
            return w

def do_trial(words, alphabets):
    o = []
    for alphabet in alphabets:
        o.append(do_test(words, alphabet))
    return " ".join(o)

out = file("out", "w")
f = file("in")

T = int(f.readline()[:-1])
for i in range(T):
    N, M = [int(x) for x in f.readline().split()]
    words = []
    for j in range(N):
        words.append(f.readline()[:-1])
    alphabets = []
    for j in range(M):
        alphabets.append(f.readline()[:-1])
    v = do_trial(tuple(words), tuple(alphabets))
    print >>out, "Case #%d: %s" % (i+1, v)
    out.flush()
