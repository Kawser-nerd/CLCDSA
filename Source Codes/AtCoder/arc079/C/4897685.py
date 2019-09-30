N = int(input())
As = list(map(int, input().split()))

ans = 0
while True:
    Bs = [A//N for A in As]
    if sum(Bs) == 0:
        print(ans)
        break
    sumB = sum(Bs)
    ans += sumB
    As = [A%N + sumB - B for A, B in zip(As, Bs)]