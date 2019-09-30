N = int(input())
S = [[str(_) for _ in input()] for _ in range(N)]
S = sum(S, [])
numT = S.count("R")
numA = S.count("B")

if numT > numA:
    print("TAKAHASHI")
elif numT < numA:
    print("AOKI")
else:
    print("DRAW")