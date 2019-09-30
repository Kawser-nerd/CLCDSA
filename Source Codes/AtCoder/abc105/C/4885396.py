N = int(input())
ans = ""
while (N != 0):
    if N%2 != 0:
        N -= 1
        ans = "1" + ans
    else:
        ans = "0" + ans
    N = int(N/-2)
if ans == "":
    print("0")
else:
    print(ans)