n = int(input())
li_a = list()
for i in range(n):
    li_a.append(int(input()))

li_a_sorted = sorted(list(set(li_a)))
d_rank = dict()

for idx, v in enumerate(li_a_sorted):
    d_rank[v] = idx

for i in li_a:
    print(d_rank[i])