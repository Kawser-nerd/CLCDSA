A,B,C = map(int,input().split())

if A*C <= B:
    print(C)
else:
    print(B//A)