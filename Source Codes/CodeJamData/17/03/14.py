def lg2(x):
    i = 0
    while x >= 2**i:
        i += 1
    return i-1

for tc in range(1, int(input())+1):
    N, K = list(map(int,input().split()))
    N += 1
    Kpow = 2**(lg2(K)+1)
    v = Kpow - K - 1
    ans = (N + v)//(2**lg2(K))
    print ("Case #%d: %d %d"%(tc,(ans-1)//2, (ans-2)//2))