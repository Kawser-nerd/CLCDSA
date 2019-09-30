import sys
S = [1 if i =='1' else 0 for i in input()]
l=len(S)
if l%2==1:
    t=l//2
    a = S[t]
    for i in range(1,t+1):
        if S[t-i]!=a or S[t+i]!=a:
            print(t+i)
            sys.exit()
    print(l)
    sys.exit()
if l%2==0:
    t=l//2
    a = S[t-1]
    b=S[t]
    if a!=b:
        print(t)
        sys.exit()
    for i in range(1,t):
        if S[t-1-i]!=a or S[t+i]!=a:
            print(t+i)
            sys.exit()
    print(l)
    sys.exit()