N=int(input())
A,B=map(int,input().split())

if A==B:
    if N<=A:
        print("Takahashi")
    elif N%(A+1)==0:
        print("Aoki")
    else:
        print("Takahashi")
elif A>B:
    print("Takahashi")
else:
    if N<=A:
        print("Takahashi")
    else:
        print("Aoki")