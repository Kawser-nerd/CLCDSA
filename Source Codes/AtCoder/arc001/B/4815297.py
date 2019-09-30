a,b = map(int,input().split())
cnt = 0
Y = set([a])
D = [1, 5, 10, -1, -5, -10]

while True:
    if b in Y:
        print(cnt)
        break
    X = Y
    cnt += 1
    Y = set([x+d for x in X for d in D if -10 < x+d < 50])