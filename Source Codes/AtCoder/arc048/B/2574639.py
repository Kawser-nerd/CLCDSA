import bisect
from collections import defaultdict

N = int(input())
RH = [list(map(int, input().split())) for i in range(N)]
R = []
D = defaultdict(lambda: {1: 0, 2: 0, 3: 0})

for r, h in RH:
    R.append(r)
    D[r][h] += 1

R.sort()

for r, h in RH:
    bl, br = bisect.bisect_left(R, r), bisect.bisect_right(R, r)
    win = bl
    lose = N-br
    even = 0

    if br-bl > 1:
        win += D[r][h % 3 + 1]
        lose += D[r][(h+1) % 3 + 1]
        even = D[r][(h+2) % 3 + 1] - 1  # ?????????
        
    print(win, lose, even)