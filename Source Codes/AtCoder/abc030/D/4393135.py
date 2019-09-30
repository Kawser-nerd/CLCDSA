#https://kimiyuki.net/writeup/algo/atcoder/abc-030/
n, a = (int(i) for i in input().split())
k = int(input())
b = list(int(i) for i in input().split())

hist = []
while a not in hist:
    hist.append(a)
    a = b[a-1]
init = hist[0 : hist.index(a)]
loop = hist[hist.index(a) : ]

if k < len(init):
    print(init[k])
else:
    print(loop[(k - len(init)) % len(loop)])