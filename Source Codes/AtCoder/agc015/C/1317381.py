import numpy as np

Y, X, Q = map(int, input().split())

a = np.zeros((Y+1, X+1), dtype="float32")

for i in range(Y):
    a[1+i, 1:] = list(map(int, list(input())))

v_cum = np.cumsum(np.cumsum(a, axis=0), axis=1)
s_row_cum = np.cumsum(np.cumsum(a[:, :X] * a[:, 1:], axis=0), axis=1)
s_col_cum = np.cumsum(np.cumsum(a[:Y, :] * a[1:, :], axis=0), axis=1)

result = []
for q in range(Q):
    y1, x1, y2, x2 = map(int, input().split())
    vertices = v_cum[y2, x2] - v_cum[y2, x1 - 1] - v_cum[y1 - 1, x2] + v_cum[y1 - 1, x1 - 1]
    sides_row = s_row_cum[y2, x2-1] - s_row_cum[y2, x1-1] - s_row_cum[y1-1, x2-1] + s_row_cum[y1-1, x1-1]
    sides_col = s_col_cum[y2-1, x2] - s_col_cum[y1-1, x2] - s_col_cum[y2-1, x1-1] + s_col_cum[y1-1, x1-1]
    result.append(vertices - sides_row - sides_col)

for q in range(Q):
    print(int(result[q]))