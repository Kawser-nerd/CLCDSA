A, B, C, D = map(int, input().split())
if B/A > D/C:
    print("TAKAHASHI")
elif B/A == D/C:
    print("DRAW")
else:
    print("AOKI")