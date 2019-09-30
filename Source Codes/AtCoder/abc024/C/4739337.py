import sys,itertools
input = sys.stdin.readline

N,D,K = map(int,input().split())
info1 = [list(map(int,input().split())) for _ in range(D)]
info2 = [list(map(int,input().split())) for _ in range(K)]
for s,t in info2:
    now = s
    day = 0
    for l,r in info1:
        day += 1
        if l <= now <= r:
            if l <= t <= r:
                print(day)
                break
            elif t < l:
                now = l
            elif r < t:
                now = r