n, q = map(int, input().split())
li_lr = list()
for i in range(q):
    li_lr.append(list(map(int, input().split())))

li_w = [0] * (n + 1)

for lr in li_lr:
    l = lr[0] - 1
    r = lr[1] - 1

    li_w[l] += 1
    li_w[r + 1] -= 1

for i in range(1, len(li_w)):
    li_w[i] = li_w[i] + li_w[i - 1]


print("".join([str(l % 2) for l in li_w[:-1]]))