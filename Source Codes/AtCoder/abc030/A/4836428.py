a, b, c, d = map(int, input().split())
l1 = b / a
l2 = d / c
if (l1 > l2):
    print("TAKAHASHI")
elif (l2 > l1):
    print("AOKI")
else:
    print("DRAW")