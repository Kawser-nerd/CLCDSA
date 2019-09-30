import math
D, G = map(int, input().split())

P = []
C = []
for i in range(D):
    p, c = map(int, input().split())
    P.append(p)
    C.append(c)

answer = sum(P)
for i in range(2**D):
    point = 0
    x = -1
    now_answer = 0
    for j in range(D):
        if i >> j & 1:
            point += P[j] * (j+1) * 100 + C[j]
            now_answer += P[j]
        else:
            x = j

    if G <= point:
        answer = min(now_answer, answer)
    else:
        n = math.ceil((G - point) / ((x+1) * 100))
        if n < P[x]:
            now_answer += n
            answer = min(now_answer, answer)

print(answer)