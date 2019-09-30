def solve():
    import datetime
    N = int(input())
    a = {tuple(map(int, input().split("/"))) for _ in [0]*N}
    today = datetime.date(2012, 1, 1)
    day = datetime.timedelta(days = 1)
    result = 0
    cur = 0
    stock = 0

    for i in range(366):
        p = today.month, today.day
        n = (not 0 < i%7 < 6) + (p in a) + stock - 1
        if n >= 0:
            stock = n
            cur += 1
            if result < cur:
                result = cur
        else:
            cur = 0
            stock = 0
        today += day

    print(result)


if __name__ == "__main__":
    solve()