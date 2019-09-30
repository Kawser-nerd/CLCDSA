def main():
    N, H = map(int, input().split())
    ma = 0
    B = []
    for _ in range(N):
        a, b = map(int, input().split())
        ma = max(ma, a)
        B.append(b)
    B.sort(reverse=True)
    ans = 0
    for b in B:
        if 0 >= H:
            print(ans)
            return
        if ma >= b or 0 >= H:
            break
        H -= b
        ans += 1
    if H > 0:
        ans += H // ma
        if H % ma != 0:
            ans += 1
    print(ans)


main()