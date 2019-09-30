N,A,B=map(int,input().split())
if N%(A+B)==0:
    print("Bug")
elif N%(A+B)<=A:
    print("Ant")
else:
    print("Bug")