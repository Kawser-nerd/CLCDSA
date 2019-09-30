def d_bigbang(N, A, B):  # ????1??/2???????
    def dist2(vec1, vec2):
        # ????vec1, vec2????vec2-vec1???
        return (vec2[0] - vec1[0])**2 + (vec2[1] - vec1[1])**2

    # ???????????????????????
    a = list(zip(*A))
    b = list(zip(*B))

    gravity_center_1st_day = (sum(a[0]) / N, sum(a[1]) / N)
    gravity_center_2nd_day = (sum(b[0]) / N, sum(b[1]) / N)

    max_distance_from_gravity_center_1st_day = \
        max([dist2(gravity_center_1st_day, u) for u in A])
    max_distance_from_gravity_center_2nd_day = \
        max([dist2(gravity_center_2nd_day, v) for v in B])

    # ???(???2???????????????)
    ans = '{0:.10f}'.format((max_distance_from_gravity_center_2nd_day
                             / max_distance_from_gravity_center_1st_day)**0.5)
    return ans
  
N = int(input())
A = [[int(i) for i in input().split()] for j in range(N)]
B = [[int(i) for i in input().split()] for j in range(N)]
print(d_bigbang(N, A, B))