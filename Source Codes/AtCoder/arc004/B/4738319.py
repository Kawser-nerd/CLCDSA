N = int(input())
d = [int(input()) for _ in range(N)]
if len(d) == 1:
    print(d[0],d[0])
else:
    e = sorted(d,reverse=True)
    #print('need to calc')
    #print('max,sum of rest ',e[0],sum(e[1:]))
    if e[0] <= sum(e[1:]):
        print(sum(d))
        print(0)
    else:
        #print('too long max(d)')
        print(sum(d))
        print(e[0]-sum(e[1:]))