N = int(input())
A, B = map(int, input().split())

if A != B:
    if A >= N:
        print("Takahashi")
    elif N-1 <= B:
        print("Aoki")
    elif A > B:
        print("Takahashi")
    else:
        print("Aoki")

else:
    if N % (A+1) == 0:
        print("Aoki")
    else:
        print("Takahashi")