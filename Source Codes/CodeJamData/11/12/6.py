# Solution for Google Code Jam 2011 Round 1A Problem B
# Copyright (c) Dan Bjorge, 2011
# All rights reserved

import copy, sys

def debug_print(s):
    temp = sys.stdout
    sys.stdout = sys.__stdout__
    print s
    sys.stdout = temp

def solve_list(worddict, wordlist, lorder):
    best = wordlist[0]
    bestscore = 0
    for answer in wordlist:
        possibles = copy.deepcopy(worddict)
        score = 0
        for word in wordlist:
            if len(word) != len(answer):
                possibles.remove(word)
        for letter in lorder:
            used = False
            for word in possibles:
                if letter in word:
                    used = True
                    is_match = [False] * len(answer)
                    for i, aletter in enumerate(answer):
                        if letter == aletter:
                            is_match[i] = True
            if not used:
                continue
            if not any(is_match):
                score += 1
            to_remove = []
            for word in possibles:
                for i in range(len(word)):
                    if (word[i]==letter) != is_match[i]:
                        to_remove.append(word)
                        break
            for word in to_remove:
                possibles.remove(word)
        if score > bestscore:
            bestscore = score
            best = answer
    return best            

def solve_case(infile):
    N, M = map(int, infile.readline().rstrip().split(' '))
    worddict = set()
    wordlist = list()
    for i in range(N):
        n = infile.readline().rstrip()
        worddict.add(n)
        wordlist.append(n)
    answers = [solve_list(worddict, wordlist, infile.readline().rstrip()) for i in range(M)]
    for a in answers[:-1]:
        print a,
    print answers[-1]
        

import argparse, os, sys
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('input_file')
    parser.add_argument('-o', '--output_file', default=None)
    args = parser.parse_args()
    if args.output_file is None:
        args.output_file = os.path.splitext(args.input_file)[0] + '.out'
    
    with open(args.output_file, 'w', 0) as outfile:
        with open(args.input_file, 'r') as infile:
            num_cases = int(infile.readline().rstrip())
            sys.stdout = outfile
            for case in range(num_cases):
                print "Case #{!s}:".format(case+1),
                solve_case(infile)
            sys.stdout = sys.__stdout__
        
