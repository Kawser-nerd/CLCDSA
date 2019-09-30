n = int(input())
sp = [[i for i in input().split()] for i in range(n)]

max_p = 0
max_s = ""
sum_p = 0
for s, p in sp:
    p = int(p)
    sum_p += p
    if max_p < p:
        max_p = p
        max_s = s


if max_p > sum_p/2:
    print(max_s)
else:
    print("atcoder")