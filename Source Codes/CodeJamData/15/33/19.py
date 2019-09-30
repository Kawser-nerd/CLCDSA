fin = open("largeC.in", "r")
fout = open("largeC.out", "w+")

for tc in xrange(int(fin.readline())):
    C,D,T = [int(x) for x in fin.readline().split()]
    coins = [int(x) for x in fin.readline().split()]

    cur, ans = 1, 0
    for coin in coins:
        if cur >= coin:
            cur += coin*C
        else:
            while cur < coin and cur <= T:
                cur *= C+1
                ans += 1
            cur += coin*C
    while cur <= T:
        cur *= C+1
        ans += 1


    print "Case #%i: %i" %(tc+1, ans)
    fout.write("Case #%i: %i\n" %(tc+1, ans))