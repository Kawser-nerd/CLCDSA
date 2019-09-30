import sys
input=sys.stdin.readline
import operator
n,m=map(int,input().split())
l_ab=[0]*m
for i in range(m):
    l_ab[i]=list(map(int,input().split()))

l_ab.sort(key=operator.itemgetter(1))
#l_br=[]
l_br_last=0
num_br=0
for i in range(m):
    #if bisect.bisect_left(l_br,l_ab[i][0])==len(l_br):
    #if l_br[-1]<l_ab[i][0]:
        #l_br.append(l_ab[i][1]-1)
    if l_br_last<l_ab[i][0]:
        l_br_last=l_ab[i][1]-1
        num_br+=1
print(num_br)