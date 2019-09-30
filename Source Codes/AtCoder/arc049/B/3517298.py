N = int(input())
x = [0 for i in range(N)]
y = [0 for i in range(N)]
c = [0 for i in range(N)]
for i in range(N):
    x[i], y[i], c[i] = map(int, input().split())

a = 0
b = 10 ** 10
inf = 10 ** 11
while b - a > 1e-5:
    d = (a + b) / 2
    distance = [0 for i in range(N)]
    x_lim_u = [0 for i in range(N)]
    x_lim_o = [0 for i in range(N)]
    y_lim_u = [0 for i in range(N)]
    y_lim_o = [0 for i in range(N)]
    for i in range(N):
        distance[i] = d / c[i]
    for i in range(N):
        x_lim_u[i] = x[i] - distance[i]
        x_lim_o[i] = x[i] + distance[i]
        y_lim_u[i] = y[i] - distance[i]
        y_lim_o[i] = y[i] + distance[i]
    x_limu, x_limo, y_limu, y_limo = x_lim_u[0], x_lim_o[0], y_lim_u[0], y_lim_o[0]
    for i in range(1, N):
        if x_limu <= x_lim_u[i] <= x_lim_o[i] <= x_limo:
            x_limu = x_lim_u[i]
            x_limo = x_lim_o[i]
        elif x_limu <= x_lim_u[i] <= x_limo < x_lim_o[i]:
            x_limu = x_lim_u[i]
        elif x_lim_u[i] < x_limu <= x_lim_o[i] <= x_limo:
            x_limo = x_lim_o[i]
        elif x_lim_u[i] <= x_limu <= x_limo <= x_lim_o[i]:
            pass
        else:
            x_limu, x_limo = inf, inf
            break
    for i in range(1, N):
        if y_limu <= y_lim_u[i] <= y_lim_o[i] <= y_limo:
            y_limu = y_lim_u[i]
            y_limo = y_lim_o[i]
        elif y_limu <= y_lim_u[i] <= y_limo < y_lim_o[i]:
            y_limu = y_lim_u[i]
        elif y_lim_u[i] < y_limu <= y_lim_o[i] <= y_limo:
            y_limo = y_lim_o[i]
        elif y_lim_u[i] <= y_limu <= y_limo <= y_lim_o[i]:
            pass
        else:
            y_limu, y_limo = inf, inf
            break
    if y_limu != inf and x_limu != inf:
        b = d
    else:
        a = d
print(d)