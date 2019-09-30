n = int(input())
base_t, a = map(int, input().split())
hs = list(map(int, input().split()))

t = [base_t - 0.006 * x for x in hs]
dif = [abs(ti - a) for ti in t]

for i in range(n):
    if dif[i] == min(dif):
        print(i+1)