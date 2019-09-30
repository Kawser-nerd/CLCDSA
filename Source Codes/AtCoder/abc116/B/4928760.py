s = int(input())
a = s
already = set()
already.add(a)
for i in range(10000000):
    if a % 2:
        a = 3 * a + 1
        if {a} <= already:
            print(i + 2)
            exit(0)
        already.add(a)
    else:
        a //= 2
        if {a} <= already:
            print(i + 2)
            exit(0)
        already.add(a)