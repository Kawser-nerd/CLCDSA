N, Y = map(int, input().split())
for x in range(N+1):
    for y in range(N+1):
        if Y == 10000*x+5000*y+1000*(N-x-y) and N-x-y >=0:
            print("{} {} {}".format(x,y,N-x-y))
            break
    else:
        continue
    break
else:
    print("-1 -1 -1")