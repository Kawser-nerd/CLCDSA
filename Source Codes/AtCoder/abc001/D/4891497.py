import math


class Time():
    def __init__(self, hhmm):
        self.h = int(hhmm[:2])
        self.m = int(hhmm[-2:])

    def hhmm(self):
        return '{:02d}{:02d}'.format(self.h, self.m)

    def round_down(self):
        self.m = self.m // 5 * 5

    def round_up(self):
        self.m = math.ceil(self.m / 5) * 5
        if self.m == 60:
            self.m = 0
            self.h += 1


memos = []
n = int(input())
for i in range(n):
    start, end = [Time(x) for x in input().split('-')]
    start.round_down()
    end.round_up()
    memos.append((start.hhmm(), end.hhmm()))

memos.sort()
result = [memos.pop(0)]

for i in memos:
    if i[0] <= result[-1][1]:
        result[-1] = (min(result[-1][0], i[0]), max(result[-1][1], i[1]))
    else:
        result.append(i)

for i in result:
    print('-'.join(i))