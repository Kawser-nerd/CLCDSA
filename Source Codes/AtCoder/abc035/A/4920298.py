W, H = map(int, input().split())
wW = W / 4
hH = wW * H
if (3 * wW) == H:
    print('4:3')
else:
    print('16:9')