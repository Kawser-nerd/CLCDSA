INF, MOD = float("inf"), 1e9 + 7
MAX, MIN = -INF, INF
dx1, dy1, dx2, dy2 = [-1, 0, 1, 0], [0, -1, 0, 1], [-1, 0, 1, -1, 1, -1, 0, 1], [-1, -1, -1, 0, 0, 1, 1, 1]

def get_int():
    return int(input())

def get_int_list():
    return list(map(int, input().split()))

def mins(x, y):
    x = min(x, y)

def maxs(x, y):
    x = max(x, y)

while(True):
    try:
        n = get_int()
        a = get_int_list()
        print(*(a[::-2] + a[1::2]) if n % 2 else a[::-2] + a[::2])
    except EOFError:
        exit()