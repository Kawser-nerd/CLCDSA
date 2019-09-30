N = int(input())
ans = 0
bool1 = False

a0 = int(input())
if N == 1:
    if a0 != 0:
        print(-1)
    else:
        print(0)

else:
    for i in range(N-1):
        a1 = int(input())
        if i == 0 and a0 != 0:
            bool1 = True
            break
        if a1 - a0 > 1:
            bool1 = True
            break
        elif a1 - a0 == 1:
            a0 = a1
            continue
        else:
            ans += a0
            a0 = a1

    if bool1 == True:
        print(-1)
    else:
        print(ans + a1)