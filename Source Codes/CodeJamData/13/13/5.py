import numpy as np

R=100
N=3
M=5
K=7

db = {}
for i in range(2,M+1):
    for j in range(2,M+1):
        for k in range(2,M+1):
            p = {}
            for n1 in range(2):
                for n2 in range(2):
                    for n3 in range(2):
                        num = i**n1 * j**n2 * k**n3

                        if num not in p:
                            p[num] = 1
                        else:
                            p[num]+=1

            db[(i,j,k)]=p

f = open('small.in')
t = int(f.readline())

#R,N,M,K = (int(x) for x in f.readline().split())
(int(x) for x in f.readline().split())
print R,N,M,K
print 'Case #1:'

for T in range(R):
    products = [int(x) for x in f.readline().split()]
    m = 0
    ans = (0,0,0)
    for i in range(2,M+1):
        for j in range(2,M+1):
            for k in range(2,M+1):
                l = 1
                for product in products:
                    if product in db[(i,j,k)]:
                        l *= db[(i,j,k)][product]
                    else: l=0
                if l > m:
                    m = l
                    ans = (i,j,k)
    print '%d%d%d'%(ans[0],ans[1],ans[2])