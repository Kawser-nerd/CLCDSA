N = int(input())
ans = 1
while True:
    ans *= 2
    if N < ans:
        print(ans//2)
        break
    elif N == ans:
        print(ans)
        break