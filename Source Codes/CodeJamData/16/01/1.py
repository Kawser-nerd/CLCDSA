t = int(input())

for cs in range(1, t + 1):
    n = int(input())
    if (n == 0):
        ans = "INSOMNIA"
    else:
        exists = set()
        cnt = 0
        now = 0
        while (cnt < 10):
            now += n
            nowstr = str(now)
            for c in nowstr:
                if (int(c) not in exists):
                    exists.add(int(c))
                    cnt += 1
        ans = str(now)
    print("Case #" + str(cs) + ": " + ans)



