from fractions import gcd
 
def gcdL(L):
    g=L[0]
    for i in range(1,len(L)):
        if g==1:
            return(g)
        g=gcd(g,L[i])
    return g
def play(A,i):
    A[i]-=1
    g=gcdL(A)
    return [x//g for x in A]
def cnt(A):
    odd,even=0,0
    for a in A:
        if a%2:
            odd+=1
        else:
            even+=1
    return odd,even    

n=int(input())
A=list(map(int,input().split()))
First=1
while True:
    odd,even=cnt(A)
    if even%2:
        print('First' if First else 'Second')
        break
    elif odd>1:
        print('Second' if First else 'First')
        break
    else:
        for i in range(n):
            if A[i]%2:
                break
        if A[i]==1:
            print('Second' if First else 'First')
            break
        else:
            A=play(A,i)
            First^=1