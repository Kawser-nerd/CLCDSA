N, Z, W = map(int, input().split())
As = list(map(int, input().split()))

num = abs(As[-1] - W)
if N == 1:
    print(num)
else:
    print(max(num, abs(As[-2] - As[-1])))