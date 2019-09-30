n, a, b = map(int, input().split())
s = [int(input()) for i in range(n)]

ave = sum(s)/n
max_s = max(s)
min_s = min(s)

if max_s-min_s != 0:
    p1, p2 = b/(max_s-min_s), -b/(max_s-min_s)
    q1, q2 = a-p1*ave, a-p2*ave
    print(p1, q1)
    
else:
    if b != 0:
        print(-1)
    else:
        print(0, a)