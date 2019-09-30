N, Y = map(int, input().split())

# F=Fukuzawa H=Higuchi S=Souseki
flg = False
for f in range(N+1):
    for h in range(N+1-f):
        if f * 10000 + h * 5000 + (N - f - h) * 1000 == Y and N-f-h >= 0:
            print("{} {} {}".format(f, h, (N - f - h)))
            flg = True
            break
    if flg is True:
        break

if flg is False:
    print("-1 -1 -1")