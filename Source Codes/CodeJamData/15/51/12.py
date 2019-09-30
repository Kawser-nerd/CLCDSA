'''
cat test_a.txt | python problem_a.py
cat A-small-attempt0.in | python problem_a.py >A-small-attempt0.out
cat A-large.in | python problem_a.py >A-large.out
'''

from sys import stdin
import array

def min_max(s, m):
    min_s = array.array('i', (-1 for _ in s))
    min_s[0] = s[0]
    max_s = array.array('i', (-1 for _ in s))
    max_s[0] = s[0]
    todo = range(1, len(min_s))
    while todo:
        i = todo.pop()
        # print "{} {} {} {}".format(len(min_s), len(m), i, m[i] % i)
        if min_s[m[i] % i] == -1:
            todo.append(i)
            todo.append(m[i] % i)
        else:
            min_s[i] = min(s[i], min_s[m[i] % i])
            max_s[i] = max(s[i], max_s[m[i] % i])
    return sorted((min_s[i], max_s[i]) for i in xrange(len(min_s)))

def solve(s, m, d):
    mm = min_max(s, m)
    best_count = -1
    for i, (min_s, _max_s) in enumerate(mm):
        count = 0
        for j in xrange(i, len(mm)):
            if min_s + d < mm[j][0]:
                break
            if mm[j][1] <= min_s + d:
                count += 1 
        if count > best_count:
            best_count = count
    return best_count

def main():
    tt = int(stdin.readline().strip())
    for t in xrange(1, tt+1):
        (n, d) = (int(s) for s in stdin.readline().strip().split(' '))
        (s_last, As, Cs, Rs) = (int(s) for s in stdin.readline().strip().split(' '))
        (m_last, Am, Cm, Rm) = (int(s) for s in stdin.readline().strip().split(' '))
        s = array.array('i')
        s.append(s_last)
        m = array.array('i')
        m.append(m_last)
        for _ in xrange(n-1):
            s_last = (s_last*As + Cs) % Rs
            s.append(s_last)
            m_last = (m_last*Am + Cm) % Rm
            m.append(m_last)
        print "Case #{}: {}".format(t, solve(s, m, d))

main()
