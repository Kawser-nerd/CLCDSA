import sys
from operator import itemgetter
from itertools import product

N = int(input())
a = [list(map(int, l.split())) for l in sys.stdin]
rotated = [(x+y, x-y) for x, y in a]
max_x, min_x = max(rotated)[0], min(rotated)[0]
max_y, min_y = max(rotated, key=itemgetter(1))[1], min(rotated, key=itemgetter(1))[1]
length = max(1, max_x-min_x, max_y-min_y)
if length % 2:
    length += 1

for x, y in product((min_x+length//2, max_x-length//2), (min_y+length//2, max_y-length//2)):
    if len({max(abs(x-_x), abs(y-_y)) for _x, _y in rotated}) == 1:
        answer_x = (x+y)//2
        answer_y = -y + answer_x
        if -(10**9) <= answer_x <= 10**9 and -(10**9) <= answer_y <= 10**9:
            print(answer_x, answer_y)
            exit()

raise Exception("hoge")