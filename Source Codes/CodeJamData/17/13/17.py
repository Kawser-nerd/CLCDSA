INF = 1000000000

def check(hd, ad, hk, ak, b, d, num_buff, num_debuf):
    count = 0
    health = hd
    while True:
        count += 1
        if num_debuf:
            if health <= ak - d:
                health = hd
            else:
                num_debuf -= 1
                ak -= d
                if ak < 0:
                    ak = 0
        elif num_buff:
            if health <= ak:
                health = hd
            else:
                num_buff -= 1
                ad += b
        elif health <= ak and ad < hk:
            health = hd
        else:
            hk -= ad
        if hk <= 0:
            return count
        health -= ak
        if health <= 0:
            return INF
        if count >= num_buff + num_debuf + 202:
            return INF

def solve(test_num):
    hd, ad, hk, ak, b, d = map(int, input().split())
    ans = INF
    for x in range(0, 101):
        for y in range(0, 101):
            ans = min(ans, check(hd, ad, hk, ak, b, d, x, y))
    if ans == INF:
        ans = "IMPOSSIBLE"
    print("Case #", test_num, ": ", ans, sep="")

for i in range(1, int(input()) + 1):
    solve(i)

