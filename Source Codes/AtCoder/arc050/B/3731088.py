R, B = map(int, input().split())
x, y = map(int, input().split())


def able(z):
    X = R - z
    Y = B - z
    return X//(x-1) + Y//(y-1) >= z

low = 0
high = min(R, B)

while high > low + 1:
    mid = (high + low)//2
    if able(mid):
        low = mid
    else:
        high = mid

if able(high):
    print(high)
else:
    print(low)