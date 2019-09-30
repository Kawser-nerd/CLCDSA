#!/usr/bin/pypy

import itertools,math,sys

def simple_solve(N,S):
    S = sorted(S)
    cnt = 0
    for perm in itertools.permutations(S):
        z = "".join(perm)
        chars = [False for _ in range(26)]
        last = ''
        for c in z:
            if last==c:
                continue
            last = c
            if chars[ord(c)-ord('a')]:
                break
            chars[ord(c)-ord('a')] = True
        else:
            cnt += 1
    return cnt

def true_solve(N,S):
    rz = {}
    for c in range(26):
        char = chr(c+ord('a'))
        cnt_inside = cnt_left = cnt_right = cnt_full = 0
        left_char = right_char = ""
        for z in S:
            h = False
            last = ""
            for x in z:
                if x==char and h and last != char:
                    return 0
                if x==char:
                    h = True
                last = x
            if z[0] == z[-1] == char:
                cnt_full += 1
            elif z[0] == char:
                cnt_left += 1
                right_char = z[-1]
            elif z[-1] == char:
                cnt_right += 1
                left_char = z[0]
            elif h:
                cnt_inside += 1
        if cnt_inside > 1 or cnt_inside > 0 and cnt_left+cnt_right+cnt_full>0 or cnt_left>1 or cnt_right>1:
            return 0
        if cnt_inside == 0 and cnt_left+cnt_right+cnt_full>0:
            rz[char] = ((left_char,right_char,math.factorial(cnt_full)))
    blocks = 0
    bb = 1
    while rz:
        for c,v in rz.items():
            if v[0]=="":
                break
        else:
            return 0
        del rz[c]
        bb *= v[2]
        while v[1] != "":
            if v[1] not in rz:
                return 0
            v = rz.pop(v[1])
            bb *= v[2]
        blocks += 1
    return math.factorial(blocks)*bb%1000000007

def solve():
    N = int(raw_input())
    S = raw_input().strip().split()
    val1 = true_solve(N,S)
    #val2 = simple_solve(N,S)
    #if val1 != val2:
    #    print "Bad"
    #    print N,S
    #    print val1,val2
    #    sys.exit(1)
    return val1

T = int(raw_input())
for t in range(1,T+1):
    print "Case #%d:"%t,solve()
