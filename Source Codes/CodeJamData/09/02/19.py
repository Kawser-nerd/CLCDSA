import numpy
import scipy
import sys
import csv
from numpy import zeros
from numpy import size

def __main__():
    input = sys.argv[1]

    r = csv.reader(open(input),delimiter=' ',quoting=csv.QUOTE_NONE)
    n=int(r.next()[0])
    for i in range(0,n):
        [row, col] = r.next(); row = int(row); col = int(col)
        m = zeros([row,col],dtype=int)
        for x in range(0,row):
            line = r.next()
            for y in range(0,col):
                m[x,y] = int(line[y])
        print "Case #"+str(i+1)+": "
        result = solve(m)
        for j in range(0,row):
            print result[j]

def solve(m):
    row = size(m,0); col = size(m,1)
#    mask = zeros([row, col],dtype = bool)
    flag = zeros([row, col],dtype = int)
#    strm = zeros([row, col],type = str)
    
    count = 0
    for x in range(0,row):
        for y in range(0,col):
            if is_sink(m,x,y):
#                print x,y
                count = count + 1
                trace(m,flag,x,y,count);
    result = translate(flag)
    
    return(result)            
    
def translate(flag):
#    print(flag)
    row = size(flag,0); col = size(flag,1)
    strm = zeros([row, col],dtype = str)
    strm[0,0]='a'
    strm[flag==flag[0,0]]='a'
    chr_i = 97
    for x in range(0,row):
        for y in range(0,col):
            if (strm[x,y]==''):
                chr_i = chr_i + 1
                strm[flag==flag[x,y]]=chr(chr_i)
    result = []
    for x in range(0,row):
        result_x= strm[x,0]
        for y in range(1,col):
            result_x = result_x + ' ' + strm[x,y]
        result.append(result_x)
        
    return(result)
    
def is_sink(m, x, y):
    row = size(m,0); col = size(m,1)
    if (x == 0 or m[x-1,y]>=m[x,y]) and \
        (x == row-1 or m[x+1,y]>=m[x,y]) and \
        (y == 0 or m[x,y-1]>=m[x,y]) and \
        (y == col-1 or m[x,y+1]>=m[x,y]):
        return(True)
    else:
        return(False)
        
def trace(m,flag,x,y,count):
    row = size(m,0); col = size(m,1)
    if (x<0 or x==row or y<0 or y==col):
        return()
    if (flag[x,y]!=0):
        return()

    flag[x,y] = count
    
    if is_flow(m,x-1,y,1,0,4):
        trace(m,flag,x-1,y,count)
    if is_flow(m,x+1,y,-1,0,1):
        trace(m,flag,x+1,y,count)
    if is_flow(m,x,y-1,0,1,3):
        trace(m,flag,x,y-1,count)
    if is_flow(m,x,y+1,0,-1,2):
        trace(m,flag,x,y+1,count)
        
    return()
    
def is_flow(m,x,y,dx,dy,weight):
    row = size(m,0); col = size(m,1)
    if (x<0 or x==row or y<0 or y==col):
        return(False)
    
    count = 0
    weight = - weight * 0.1
    s = m[x,y]-m[x+dx,y+dy]+weight

    if (s<0):
        return(False)
    
    if (x==0 or (s >= m[x,y]-m[x-1,y]-0.1)):
        count = count + 1
    if (x==row-1 or (s >= m[x,y]-m[x+1,y]-0.4)):
        count = count + 1
    if (y==0 or (s >= m[x,y]-m[x,y-1]-0.2)):
        count = count + 1
    if (y==col-1 or (s >= m[x,y]-m[x,y+1]-0.3)):
        count = count + 1
    
    if (count==4):
#        print "is flow"
        return(True)
    else:
        return(False)
    
    
if __name__ == '__main__': __main__()