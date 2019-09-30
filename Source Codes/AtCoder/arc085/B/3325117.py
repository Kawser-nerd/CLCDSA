ai = lambda: list(map(int,input().split()))
n, z, w = ai()
a = ai()
if n == 1:
    print(abs(a[-1]-w))
else:
    print(max(abs(a[-1]-w), abs(a[-1]-a[-2])))