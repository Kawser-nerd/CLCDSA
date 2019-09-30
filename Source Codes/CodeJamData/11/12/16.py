#!/usr/bin/python
#b.py
#Author: James Damore
#Created on: May 20, 2011
#Time-stamp: <2011-05-20 22:34:03>
#cat Downloads/-small-attempt0.in | ~/python/codeJam/b.py > output.txt

import math
import string
import sys

def equivalent(word1, word2, letter):
    length = len(word1)
    if len(word2) != length:
        return False
    return all(((word1[i] == letter) == (word2[i] == letter) for i in range(length)))

def array(size, default = None): return [default for _ in range(size)]
def matrix(r, c, default = None):
    return [array(c, default) for row in range(r)]

def read_ints(lines = 1):
    if lines == 1: return map(int, raw_input().split())
    return [map(int, raw_input().split()) for _ in range(lines)]

def cat(array):
    return reduce(lambda x, y: x+y, [''] + array)

def read_input():
    N, M = read_ints()
    dictionary = [raw_input() for _ in range(N)]
    lists = [raw_input() for _ in range(M)]
    #print dictionary
    #print lists
    maxIndex = matrix(N, M)
    for iw, word in enumerate(dictionary):
        for iL, L in enumerate(lists):
            maxIndex[iw][iL] = max([L.find(w) for w in word])
    maxEquivalent = matrix(N, N, [])
    for i in range(N):
        for j in range(N):
            maxEquivalent[i][j] = array(M, 0)
    for iw, word in enumerate(dictionary):
        for iL, L in enumerate(lists):
            for iw2, word2 in enumerate(dictionary):
                if word != word2:                    
                    for i in range(26):
                        if equivalent(word, word2, L[i]):
                            maxEquivalent[iw][iw2][iL] += 1
                        else:
                            break
                if len(word) != len(word2):
                    maxEquivalent[iw][iw2][iL] = -1
    #print maxEquivalent  
    output = []
    for iL, L in enumerate(lists):
        maxScore = 0
        winner = dictionary[0]
        for iw, word in enumerate(dictionary):
            score = 0
            for iletter, letter in enumerate(L[:maxIndex[iw][iL]]):                   
                if letter in cat([w for i, w in enumerate(dictionary) if maxEquivalent[iw][i][iL] >= iletter]):
                    if letter not in word:
                        score += 1
            #print score, word
            maxScoreNew = max(score, maxScore)
            if maxScoreNew > maxScore:
                winner = word
                maxScore = maxScoreNew
        output.append(winner)
    return ' '.join(output)


numCases=input()
for i in range(1, numCases+1):
    #read_input()
    output = read_input()
    print "Case #%d:" % i, output
