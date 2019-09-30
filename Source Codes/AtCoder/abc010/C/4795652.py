txa, tya, txb, tyb, T, V = map(int, input().split())
n = int(input())
xy = [[int(_) for _ in input().split()] for _ in range(n)]
flag = False

for i in xy:
    if ((txa-i[0])**2+(tya-i[1])**2)**0.5+((i[0]-txb)**2+(i[1]-tyb)**2)**0.5 <= T*V:
        flag = True
        break

print("YES" if flag else "NO")