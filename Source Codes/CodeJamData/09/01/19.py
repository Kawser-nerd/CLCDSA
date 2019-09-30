#import numpy
#import scipy
import sys
import csv
import copy
#from numpy import zeros
#from numpy import size

def __main__():
    input = sys.argv[1]

    r = csv.reader(open(input),delimiter=' ',quoting=csv.QUOTE_NONE)
    [l,d,n] = r.next()
    l = int(l); d = int(d); n = int(n);
    word=[];
    for i in range(0,d):
        [word_i] = r.next(); word.append(word_i)
    
    for i in range(0,n):
        [pattern_i] = r.next();
        print "Case #"+str(i+1)+": "+str(solve(copy.copy(word), pattern_i))

def solve(word, pattern):
#   print pattern
    i = 0; inclosure = False;
    count = 0; achar = False;
    while (i < len(pattern)):
        if pattern[i] == '(':
            start = i
            inclosure = True
            achar = False;
        elif pattern[i] == ')':
            end = i;
            char=pattern[(start+1):(end)];
            achar = True
            inclosure = False
#            print char
        elif not inclosure:
            char=pattern[i]
            achar = True
        if achar:
            newword = [];
            for j in range(0,len(word)):
                if char.find(word[j][count])>-1:
                    newword.append(word[j])
            word = newword
            count = count + 1
        i = i + 1
    return(len(word))
    
if __name__ == '__main__': __main__()