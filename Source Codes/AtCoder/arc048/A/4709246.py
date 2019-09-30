A,B = map(int,input().split())
if A > 0:
    print(B-A)
elif A<0 and B>0:
    print(B-A-1)
else:
    print(abs(B-A))