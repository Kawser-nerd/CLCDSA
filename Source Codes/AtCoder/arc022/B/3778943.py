def func(n, a):
    table = [0 for _ in range(10**6)]
    under = 0
    top = 0
    length = 0
    while under < len(a) and top < len(a):
        # print("under:{} top:{} table:{}".format(under, top, table))
        # ??top??????????
        while top < len(a) and table[a[top]] == 0:
            table[a[top]] = 1
            top += 1
        length = max(length, top - under)
        # print("length:{} under:{} top:{}".format(length, under, top))
        while under < top < len(a) and table[a[top]] > 0:
            table[a[under]] -= 1
            under += 1
        # ?????,???????
    print(length)

# func(7, [int(i) for i in "1 2 1 3 1 4 4".split()])
# func(1, [100])
n = int(input())
a = [int(i) for i in input().split()]
func(n, a)