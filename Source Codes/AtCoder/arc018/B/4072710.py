def b_lattice_point_and_integer(N, Pos):
    from itertools import combinations

    def surface_2(Xa, Ya, Xb, Yb, Xc, Yc):
        # 3? (Xa, Ya), (Xb, Yb), (Xc, Yc)??????????2?????
        # (Xa,Ya)?????????3?????????
        xb, yb = Xb - Xa, Yb - Ya
        xc, yc = Xc - Xa, Yc - Ya
        ret = abs(xb * yc - yb * xc)
        return ret

    ans = 0
    for i, j, k in combinations(range(N), 3):
        s = surface_2(*(Pos[i] + Pos[j] + Pos[k]))
        if s != 0 and s % 2 == 0:
            ans += 1
    return ans 

N = int(input())
Pos = [[int(i) for i in input().split()] for j in range(N)]
print(b_lattice_point_and_integer(N, Pos))