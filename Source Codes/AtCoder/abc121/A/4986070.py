HHH, WWW = map(int, input().split())
h, w = map(int, input().split())

full_cells = HHH * WWW

full_cells -= h * WWW

full_cells -= ((w * HHH) - (h * w))

print(full_cells)