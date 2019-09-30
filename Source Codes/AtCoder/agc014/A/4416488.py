def inpl(): return list(map(int, input().split()))
A, B, C = inpl()

if A%2 or B%2 or C%2:
    print(0)
elif A == B == C:
    print(-1)
else:
    ans = 1
    while True:
        A, B, C = (C+B)//2, (A+C)//2, (A+B)//2
        if A%2 or B%2 or C%2:
            print(ans)
            break
        ans += 1