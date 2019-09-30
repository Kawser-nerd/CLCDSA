import sys
import math
stdin = sys.stdin
ni = lambda: int(ns())
na = lambda: list(map(int, input().split()))
ns = lambda: input()

N,H =na()
a=[]
b=[]
for i in range(N):
    t = na()
    a.append(t[0])
    b.append(t[1])

#print(a,b)
m_a = max(a)
b.sort(reverse=True)
#print(b)
sum_b=0
b_i=0
if(m_a>b[-1]):
    for i in range(N):
        sum_b+=b[i]
        if(b[i]<=m_a):
            sum_b-=b[i]
            b_i=i
            break
else:
    b_i=N
    sum_b=sum(b)
#print(b[:b_i])
res=0
if(sum_b>=H):
    #print("upper")
    for i in range(b_i):
        res+=b[i]
        if(res>=H):
            print(i+1)
            exit()

else:
    ct=0
    #print("under",b_i)
    '''while(True):
        H-=m_a
        ct+=1
        if(sum_b>=H):
            print(ct+b_i)
            exit()
    '''
    H_resi = H-sum_b
    ct+=math.ceil(H_resi/m_a)
    print(ct+b_i)