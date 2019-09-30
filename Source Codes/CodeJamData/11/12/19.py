#!/usr/bin/env python

from sys import stdin

def compatible(word, target, letter):
    for i in range(len(word)):
        if ((word[i] == letter) ^ (target[i] == letter)):
            return False
    return True

def cost(word, dic, lis, pos=0):
    if len(dic) == 1:
        return 0
    if len([i for i in dic if lis[pos] in i]) != 0:
        if lis[pos] in word:
            return cost(word, [i for i in dic if compatible(word, i, lis[pos])], lis, pos+1)
        else:
            return 1+cost(word, [i for i in dic if lis[pos] not in i], lis, pos+1)
    else:
        return cost(word, [i for i in dic if lis[pos] not in i], lis, pos+1)

if __name__ == "__main__":
    t = input()

    for test in xrange(t):
        n, m = [int(i) for i in stdin.readline().strip().split()]
        dic = []
        result = []
        for i in xrange(n):
            dic.append(raw_input())
        for i in xrange(m):
            lis = raw_input()
            cur = dic[0]
            val = cost(dic[0], [i for i in dic if len(dic[0]) == len(i)], lis)
            for i in xrange(1, n):
                a = cost(dic[i], [j for j in dic if len(dic[i]) == len(j)], lis)
                if a > val:
                    cur = dic[i]
                    val = a
            result.append(cur)
        print "Case #%d: %s" % (test+1, " ".join(result))