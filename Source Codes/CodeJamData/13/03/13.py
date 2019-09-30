#!/usr/bin/python3.2

import sys
import math

if len(sys.argv) == 1:
    f = sys.stdin
    o = sys.stdout

if len(sys.argv) == 2:
    f = open(sys.argv[1], 'r')
    o = sys.stdout

if len(sys.argv) == 3:
    f = open(sys.argv[1], 'r')
    o = open(sys.argv[2], 'w')


def min_except(l, exc):
    l2 = sum(l, [])
    res = min([e for e in l2 if e != exc])
    return res

def rev_num(n):
    return int(''.join(list(reversed(str(n)))))

def build_pal(d, n):
    num_l = (d + 1) // 2

    sn1 = str(n)
    sn1 = '0' * (num_l - len(sn1)) + sn1

    n_rev = ''.join(list(reversed(sn1)))

    pair = (d % 2 == 0)
    if pair:
        return int(n_rev + sn1)
    else:
        return int(n_rev[:-1] + sn1)

def is_pal(n):
    ns = str(n)
    s = len(ns)
    for i in range(s):
        if ns[i] != ns[s - 1 - i]:
            return False
    return True

def fair_square(start, end):
    nb = 0

    #print(start, ' -> ', end)

    nb_digit_start= len(str(int(math.sqrt(start))))
    nb_digit_end = len(str(int(math.sqrt(end))))

    #print(nb_digit_start, ' -> ', nb_digit_end)
    for d in range(nb_digit_start, nb_digit_end + 1):
        n_d2 = (d+1)//2
        #print('')
        for n in range(10**(n_d2-1), 10**n_d2):
            #print(n)
            n = rev_num(n)
            pal = build_pal(d, n)

            #print(d, n, '->', pal, pal**2)
            if pal**2 < start:
                continue
            if pal**2 > end:
                return nb
            #print(d, n, '->', build_pal(d, n))
            if is_pal(pal**2):
                nb = nb + 1

    print(';xxxx')

    return nb

case_id = 1
nb = int(f.readline().strip())
for t in range(nb):
    l = f.readline().strip()
    sizes = l.split(' ')
    start = int(sizes[0])
    end = int(sizes[1])

    nb = fair_square(start, end)
    print('Case #%d: %d' % (case_id, nb), file = o)
    case_id += 1
    

