import sys

sys.stdin  = open("B-large.in", "r")
sys.stdout = open("B-large.out", "w")

best = 10 ** 100
ba, bb = None, None

def try0(i, a, b, pa, pb):
    global n, best, ba, bb
    if i == n:
        v = abs(int(pa) - int(pb))
        if v < best or (v == best and pa < ba) or (v == best and pa == ba and pb < bb):
            best = v
            ba = pa
            bb = pb
        return
        
    if a[i] == b[i] and a[i] != '?':
        try0(i + 1, a, b, pa + a[i], pb + b[i])
    elif a[i] == b[i] and a[i] == '?':
        if pa == pb:
            try0(i + 1, a, b, pa + '0', pb + '0')
            try0(i + 1, a, b, pa + '0', pb + '1')
            try0(i + 1, a, b, pa + '1', pb + '0')
        elif pa > pb:
            try0(i + 1, a, b, pa + '0', pb + '9')
        else:
            try0(i + 1, a, b, pa + '9', pb + '0')
    elif a[i] == '?':
        if pa == pb:
            try0(i + 1, a, b, pa + b[i], pb + b[i])
            if b[i] > '0':
                try0(i + 1, a, b, pa + str(int(b[i]) - 1), pb + b[i])
            if b[i] < '9':
                try0(i + 1, a, b, pa + str(int(b[i]) + 1), pb + b[i])
        elif pa > pb:
            try0(i + 1, a, b, pa + '0', pb + b[i])
        else:
            try0(i + 1, a, b, pa + '9', pb + b[i])
    elif b[i] == '?':
        if pa == pb:
            try0(i + 1, a, b, pa + a[i], pb + a[i])
            if a[i] > '0':
                try0(i + 1, a, b, pa + a[i], pb + str(int(a[i]) - 1))
            if a[i] < '9':                 
                try0(i + 1, a, b, pa + a[i], pb + str(int(a[i]) + 1))
        elif pa > pb:
            try0(i + 1, a, b, pa + a[i], pb + '9')
        else:
            try0(i + 1, a, b, pa + a[i], pb + '0')
    else:
        try0(i + 1, a, b, pa + a[i], pb + b[i])

tn = int(input())
for test in range(1, tn + 1):
    a, b = input().split()
    best = 10 ** 100
    ba, bb = None, None
    n = len(a)
    try0(0, a, b, "", "")
    print("Case #%d:" % test, ba, bb)

