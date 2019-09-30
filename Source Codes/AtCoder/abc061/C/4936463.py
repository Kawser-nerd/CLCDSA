N, K = map(int, input().split())
AB = []
for i in range(N):
    AB.append(list(map(int, input().split())))

AB = sorted(AB, key=lambda x: x[0])
for i in range(N):
    if i > 0:
        AB[i][1] += AB[i-1][1]
    if K <= AB[i][1]:
        print(AB[i][0])
        break