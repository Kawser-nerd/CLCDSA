import sys
N = int(input())
if N == 0:
    print("0")
    sys.exit()
ans = ""
while N != 0:
    if N % 2 == 1:
        ans = "1" + ans
        if N > 0:
            N = N // 2 *(-1)
        else:
            N = N // -2 + 1
    else:
        ans = "0" + ans
        N //= -2
print(ans)