import math
N, Q = map(int, input().split())
pyrms = [list(map(int, input().split())) for i in range(N)]


def solve(A, B):
    res = 0
    for pyrm in pyrms:
        X = pyrm[0]
        R = pyrm[1]
        H = pyrm[2]
        if A <= X and X + H <= B:
            temp = math.pi * (R ** 2) * H / 3
        elif X <= A and A <= X + H <= B:
            temp = math.pi * ((R * (X + H - A) / H) ** 2) * (X + H - A) / 3
        elif A <= X <= B and B <= X + H:
            temp = math.pi * (R ** 2) * H / 3
            temp -= math.pi * ((R * (X + H - B) / H) ** 2) * (X + H - B) / 3
        elif X <= A and B <= X + H:
            temp = math.pi * ((R * (X + H - A) / H) ** 2) * (X + H - A) / 3
            temp -= math.pi * ((R * (X + H - B) / H) ** 2) * (X + H - B) / 3
        else:
            temp = 0
        res += temp
    return res

for q in range(Q):
    A, B = map(int, input().split())
    ans = solve(A, B)
    print(ans)