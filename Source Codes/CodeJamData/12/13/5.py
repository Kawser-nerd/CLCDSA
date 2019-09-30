from collections import defaultdict, namedtuple
from itertools import *
import sys, heapq, re, math, random
from fractions import *

def D(fmt, *args):
    if args:
        print >> sys.stderr, fmt % args
    else:
        print >> sys.stderr, fmt
    return True

T = int(raw_input())

Event = namedtuple("Event", "t type i j")

for testCase in xrange(1, T+1):
    N = int(raw_input())

    C = []
    S = []
    P = []

    for i in xrange(N):
        line = raw_input().split()
        C.append(line[0])
        S.append(Fraction(line[1]))
        P.append(Fraction(line[2]))

    lock_count = [0]*N

    events = []
    for i in xrange(N):
        for j in xrange(i+1, N):
            if S[i] == S[j]:
                if abs(P[i]-P[j]) < 5:
                    lock_count[i] += 1
                    lock_count[j] += 1
                    assert D("%d, %d locked at start", i, j)
            else:
                t1 = (P[j]-P[i]-5)/(S[i]-S[j])
                t2 = (P[j]-P[i]+5)/(S[i]-S[j])
                if t2 < t1:
                    t2, t1 = t1, t2
                assert D("(%d,%d): t=(%s,%s)", i, j, t1, t2)
                if t1 >= 0:
                    events.append(Event(t1, 1, i, j))
                    events.append(Event(t2, 0, i, j))
                elif t2 >= 0:
                    lock_count[i] += 1
                    lock_count[j] += 1
                    assert D("%d, %d locked at start, unlocking at t=%s", i, j, t2)
                    events.append(Event(t2, 0, i, j))
    
    events.sort()
    assert D(events)

    forced_mask = 0
    initial_state = 0
    for i in xrange(N):
        if lock_count[i] > 0:
            forced_mask |= (1<<i)
        if C[i] == 'R':
            initial_state |= (1<<i)

    states = set()
    for state in xrange(1<<N):
        if state & forced_mask == initial_state & forced_mask:
            states.add(state)

    max_time = None

    assert D("initial: states=%s", sorted(states))
    for event in events:
        i, j = event.i, event.j
        if event.type == 1:
            next_states = set()
            for state in states:
                i_right = bool(state & (1<<i))
                j_right = bool(state & (1<<j))
                if i_right != j_right:
                    next_states.add(state)
            states = next_states
            lock_count[i] += 1
            lock_count[j] += 1
        else:
            lock_count[i] -= 1
            lock_count[j] -= 1
            next_states = set()
            for state in states:
                next_states.add(state)
                if lock_count[i] == 0:
                    next_states.add(state ^ (1<<i))
                if lock_count[j] == 0:
                    next_states.add(state ^ (1<<j))
                    if lock_count[i] == 0:
                        next_states.add(state ^ (1<<i) ^ (1<<j))
            states = next_states
        assert D("after %s: states=%s locks=%s", event, sorted(states), lock_count)
        if not states:
            assert D("stopping at t=%s", event.t)
            max_time = event.t
            break


    print "Case #%d: %s" % (testCase, "Possible" if max_time is None else float(max_time))
