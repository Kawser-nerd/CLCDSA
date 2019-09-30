import sys
N=int(input())
A=[int(i) for i in input().split()]
a=max(A)
b=min(A)
if b>=0:
    ans = []
    for i in range(1,N):
        ans.append([i,i+1])
    print(N-1)
    for a ,b in ans:
        print(a,b)
    sys.exit()
if a<=0:
    ans = []
    for i in range(1,N):
        ans.append([N-i+1,N-i])
    print(N-1)
    for a ,b in ans:
        print(a,b)
    sys.exit()  
x=A.index(a)+1
y=A.index(b)+1
if abs(a)>=abs(b):
    ans = []    
    for i in range(N):
        ans.append([x,i+1])
    for i in range(1,N):
        ans.append([i,i+1])
    print(2*N-1)
    for a ,b in ans:
        print(a,b)
    sys.exit()
if abs(b)>abs(a):
    ans = []    
    for i in range(N):
        ans.append([y,i+1])   
    for i in range(1,N):
        ans.append([N-i+1,N-i])
    print(2*N-1)
    for a ,b in ans:
        print(a,b)
    sys.exit()