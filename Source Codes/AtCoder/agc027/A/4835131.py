N, x = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
for i, a in enumerate(A):
    if x == a:
        print(i + 1)
        break
    elif x < a:
        print(i)
        break
    else:
        x -= a
else:
    print(N - 1)