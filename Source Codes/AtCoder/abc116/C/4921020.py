N = int(input())
H = list(map(int,input().split()))
cnt = 0
for _ in range(10**4):
    if any(H) is False:
        break
    cnt += 1
    f = False
    for i in range(len(H)):
        if H[i] > 0:
            H[i] -= 1
            f = True
        elif f and H[i] == 0:
            break
print(cnt)