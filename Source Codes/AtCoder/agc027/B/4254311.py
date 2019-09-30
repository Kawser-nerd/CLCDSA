from itertools import accumulate
N, X = map(int, input().split())
dust_acc = [0] + list(accumulate(list(map(int, input().split()))[::-1]))
dust_acc += [dust_acc[-1]]*N
coef = [5] + [5+i*2 for i in range(N-1)]

ans = float("inf")

for robot_count in range(1, N+1):
    cost = sum(
        (plus-minus)*c for plus, minus, c in zip(dust_acc[robot_count::robot_count], dust_acc[:N:robot_count], coef))\
        + robot_count * X

    if ans > cost:
        ans = cost

print(ans + N*X)