from sys import stdin
from numpy import *

T = int(stdin.readline())
for t in range(1,T+1):
    N,L = [int(word) for word in stdin.readline().strip().split()]

    A = array([ [int(ch) for ch in word]
        for word in stdin.readline().strip().split()], dtype=bool)
    B = array([ [int(ch) for ch in word]
        for word in stdin.readline().strip().split()], dtype=bool)

    B = B[lexsort(B.T)]

    assert A.shape == (N,L)

    fewest_flips = L+1

    for n in range(N):
        flips = logical_xor(A[0], B[n])
        Af = logical_xor(A, flips)
        Af = Af[lexsort(Af.T)]
        if (Af==B).all():
            fewest_flips = min(fewest_flips, flips.sum())

    print "Case #"+str(t)+":",
    if fewest_flips == L+1:
        print "NOT POSSIBLE"
    else:
        print fewest_flips

