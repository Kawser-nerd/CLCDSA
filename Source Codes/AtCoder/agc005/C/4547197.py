import sys
input=sys.stdin.readline
from math import ceil
input()
A=list(map(int,input().split()))
maxA=max(A)
minA=min(A)
if minA!=ceil(maxA/2):
    print('Impossible')
else:
    if maxA%2:
        for i in range(minA,maxA+1):
            if i==minA:
                if A.count(i)!=2:
                    print('Impossible')
                    break
            else:
                if A.count(i)<2:
                    print('Impossible')
                    break
        else:
            print('Possible')
    else:
        for i in range(minA,maxA+1):
            if i==minA:
                if A.count(i)!=1:
                    print('Impossible')
                    break
            else:
                if A.count(i)<2:
                    print('Impossible')
                    break
        else:
            print('Possible')