import bisect
S=input()

A=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
N=[0 for i in range(26)]
n=[i for i in range(26)]
a=[]

if S=="zyxwvutsrqponmlkjihgfedcba":
    print(-1)
elif len(S)<26:
    for i in range(len(S)):
        for j in range(26):
            if S[i]==A[j]:
                N[j]=1
    for i in range(26):
        if N[i]==0:
            S=S+A[i]
            print(S)
            exit()
else:
    S=list(S)
    for i in range(len(S)):
        for j in range(26):
            if S[i]==A[j]:
                S[i]=n[j]
    for i in range(25):
        if S[25-i]>S[24-i]:
            break
    L=S[25-i:]
    L.sort()
    X=S[:24-i]
    Y=L[bisect.bisect_left(L,S[24-i])]
    X.append(Y)
   
    for i in range(len(X)):
        for j in range(26):
            if X[i]==n[j]:
                X[i]=A[j]
    print("".join(X))