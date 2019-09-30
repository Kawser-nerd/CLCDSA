#!/usr/bin/python

from sys import *
import re

def read_ints(strLine):
    return map(int,
               strLine.rstrip('\r\n').split(' '))

def rsreadline():
    return stdin.readline().rstrip('\r\n')

def main():
    [lWord, cWord, cCase] = read_ints(stdin.readline())
    rgWord = []
    for iWord in range(0, cWord):
        rgWord.append(rsreadline())
    for iCase in range(0, cCase):
        regex = re.compile(rsreadline().replace('(', '[').replace(')', ']'))
        print "Case #%d: %d" % (iCase + 1, len(filter(lambda x: regex.match(x), rgWord)))
        stdout.flush()

main()
