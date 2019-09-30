N,L=map(int,input().split())

A=[]

for i in range(L):
    a=list(input())
    a=[" "]+a
    A.append(a)
    
#print(A)
B=[i for i in range((N)*2)]
#print(B)

for i in range(L):
    for j in range(len(A[0])):
        if A[i][j]=="-":
            B[j-1],B[j+1]=B[j+1],B[j-1]
#print(B)

M=list(input())
#print(M)

for i in range(len(M)):
    if M[i]=="o":
        print((B[i+1]+1)//2)