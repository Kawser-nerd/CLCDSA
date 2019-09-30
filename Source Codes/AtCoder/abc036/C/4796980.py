N = int(input())
lst_a = [int(input()) for _ in range(N)]


set_a = sorted(set(lst_a))
dic_a2b = {k:v for v, k in enumerate(set_a)}
for a in lst_a:
    b = dic_a2b[a]
    print(b)