A, B = map(int, input().split())
ans = 0
Y = set([A])
D = [1, 5, 10, -1, -5, -10]

while True:
    if B in Y:
        print(ans)
        break
    X = Y
    ans += 1
    Y = set([x+d for x in X for d in D if -10 < x+d < 50])