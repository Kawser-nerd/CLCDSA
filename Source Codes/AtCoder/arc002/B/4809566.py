from datetime import datetime, timedelta
def inpl(): return list(map(int, input().split()))

D = datetime.strptime(input(), "%Y/%m/%d")
delta = 0
while True:
    y, m, d = D.year, D.month, D.day
    if y%(m*d) == 0:
        print(D.strftime("%Y/%m/%d"))
        break
    D += timedelta(days=1)