import sys
from collections import Counter,defaultdict
import itertools

def go(M):
    L="ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    D=Counter(M)
    def remove(num,count):
        for c in L[num]:
            D[c]-=count
    num0 = D['Z']
    remove(0,num0)
    num2 = D['W']
    remove(2,num2)
    num4 = D['U']
    remove(4,num4)
    num6 = D['X']
    remove(6,num6)
    num7 = D['S']
    remove(7,num7)
    num8 = D['G']
    remove(8,num8)
    num5 = D['V']
    remove(5,num5)
    num1 = D['O']
    remove(1,num1)
    num3 = D['R']
    remove(3,num3)
    num9 = D['I']
    remove(9,num9)
    return '0'*num0+'1'*num1+'2'*num2+'3'*num3+'4'*num4+'5'*num5+'6'*num6+'7'*num7+'8'*num8+'9'*num9
    

#sys.stdin=open('dataa.txt')
#sys.stdin=open(r'c:\Users\Peter\Downloads\A-small-attempt0.in')

T=input()
for t in range(1,T+1):
    M=raw_input()
    print "Case #{}: {}".format(t,go(M))
