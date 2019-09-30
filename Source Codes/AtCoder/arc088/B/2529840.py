S = input()
N = len(S)

if len(set(S)) == 1:
    print(N)
    exit()

ans = N//2
l = r = N//2
if N%2 == 0: l -= 1

inside = None
while l >= 0:
    if not inside:
        if N%2:
            if S[l] == 1:
                print(N//2 + 1)
                exit()
        else:
            if S[l] != S[r]:
                print(N//2)
                exit()
        inside = S[l]
        continue
    if S[l] != inside or S[r] != inside:
        break
    inside = S[l]
    l -= 1
    r += 1
    ans += 1
print(ans)