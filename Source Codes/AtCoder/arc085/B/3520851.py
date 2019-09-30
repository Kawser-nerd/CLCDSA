N, Z, W = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
if N == 1:
    print(abs(a[-1]-W))
else:
    ans = max(abs(a[-1]-W),abs(a[-2]-a[-1]))
    print(ans)