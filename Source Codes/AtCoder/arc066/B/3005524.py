def Dp(x, hl, islim):
    if x == len(digit):
        return hl == 0
    if f[x][hl][islim]:
        return f[x][hl][islim]
    ans = 0
    mx = int(digit[x]) if islim else 1
    for i in range(mx + 1):
        ans += Dp(x + 1, hl, islim and i == mx)
        if hl != i:
            ans += Dp(x + 1, not hl, islim and i == mx)
    ans %= p
    f[x][hl][islim] = ans
    return ans

p = 10**9 + 7
digit = bin(int(input()))[2:]
f = [[[0, 0], [0, 0]] for i in range(len(digit))]
print(Dp(0, 0, 1))