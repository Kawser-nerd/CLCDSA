#!/usr/bin/env python

def solve(a, b):
    n = len(a)
    x = [-1] * n
    for i in xrange(n):
        if a[i] == 1 and b[i] == 1:
            x[i] = 1
            break
    
    def place(cur):
        best_a = [1] * n
        cur_best = 1
        for i in xrange(n):
            if x[i] > 0:
                cur_best = max(cur_best, a[i] + 1)
            best_a[i] = cur_best
        best_b = [1] * n
        cur_best = 1
        for i in reversed(range(n)):
            if x[i] > 0:
                cur_best = max(cur_best, b[i] + 1)
            best_b[i] = cur_best
        for i in xrange(n):
            if x[i] > 0:
                continue
            if a[i] == best_a[i] and b[i] == best_b[i]:
                x[i] = cur
                if (cur == n):
                    return True
                else:
                    if place(cur + 1):
                        return True
                    else:
                        x[i] = -1
        return False
    if n > 1:
        place(2)
    return x

if __name__ == "__main__":
    T = int(raw_input())
    for ncase in xrange(1, T + 1):
        n = int(raw_input())
        a = map(int, raw_input().split())
        b = map(int, raw_input().split())
        sol = solve(a, b)
        print "Case #%d:" % ncase,
        for s in sol:
            print s,
        print
