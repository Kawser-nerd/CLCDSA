""" AtCoder """

N = int(input())
w = [int(input()) for _ in range(N)]

ans = 1
p = [w[0]]

for i in range(1, N):
    if p[-1] >= w[i]:
        for j in range(i):
            if p[j] >= w[i]:
                p.pop(j)
                break
    p.append(w[i])
    p.sort()

print(len(p))