#!python
#-*- coding:utf-8 -*-

import sys
import re
import math

T = int( sys.stdin.readline() )
for index in range( 1, T + 1 ):
    N, M, K = [ int(x) for x in sys.stdin.readline().split() ]
    
    if min(N, M) <= 2:
        print "Case #%d: %d" % ( index, K )
    elif min(N, M) <= 3:
        answer = [1,2,3,4,4,5,6,6,7,8,8,9,10,10,11,12,12,13,14,14]
        if K > 3 * (max(N, M) - 1):
            print "Case #%d: %d" % ( index, answer[3 * (max(N, M) - 1) - 1] + K - 3 * (max(N, M) - 1) )
        else:
            print "Case #%d: %d" % ( index, answer[K-1] )
    elif min(N, M) <= 4:
        answer = [1,2,3,4,4,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12]
        if K > 4 * (max(N, M) - 1):
            print "Case #%d: %d" % ( index, answer[4 * (max(N, M) - 1) - 1] + K - 4 * (max(N, M) - 1) )
        else:
            print "Case #%d: %d" % ( index, answer[K-1] )
