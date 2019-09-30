import numpy
import scipy
import sys
import csv
from numpy import ones
from numpy import size
import math

def __main__():
    input = sys.argv[1]

    r = csv.reader(open(input),delimiter='\n',quoting=csv.QUOTE_NONE)
    n=int(r.next()[0])
    for i in range(0,n):
        [text] = r.next()
        print "Case #"+str(i+1)+": "+solve(text)

def solve(text):
    welcome = 'welcome to code jam'
    row = len(welcome)
    col = len(text)
    m = ones([row,col],dtype=int) * (-1)
#    print welcome
#    print text
    n = dp(m,welcome,text,0,0)
    strn = str_n(n)
    return(strn)
    
def dp(m,welcome,text,x,y):
    if (x==len(welcome)):
        return(1)
    elif (y==len(text)):
        return(0)
    elif (m[x,y]!=-1):
        return(m[x,y])
    else:
        if (welcome[x]==text[y]):
            m[x,y] = (dp(m,welcome,text,x+1,y+1)+dp(m,welcome,text,x,y+1))%10000
        else:
            m[x,y] = dp(m,welcome,text,x,y+1)
        return(m[x,y])
            
def str_n(n):
    if n==0:
        return('0000')
    
    m = int(4-(math.floor(math.log10(n))+1))
    strn = str(n)
    for i in range(0,m):
        strn = '0'+strn
    return(strn)

if __name__ == '__main__': __main__()