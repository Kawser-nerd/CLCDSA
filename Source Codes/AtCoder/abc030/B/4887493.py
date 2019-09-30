ji, fun = map(int, input().split())
if (ji >= 12):
    ji -= 12
tanshin = 6 * fun
tyoushin = 30*ji + 0.5*fun
kakudo = abs(tyoushin - tanshin)
if (kakudo >= 180):
    print(360 - kakudo)
else:
    print(kakudo)