h, w = map(int, input().split())
a = [None for i in range(h + 2)]
a[0] = ['#' for i in range(w + 2)]
a[-1] = ['#' for i in range(w + 2)]
for i in range(1, h + 1):
    a[i] = ['#'] + list(input()) + ['#']

for i in range(h + 2):
    print(''.join(a[i]))