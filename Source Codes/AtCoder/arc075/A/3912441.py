n = int(input())
s = [int(input()) for i in range(n)]
s.sort()
t = sum(s)
if t % 10 == 0:
    for v in s:
        if v % 10 != 0:
            print(t - v)
            exit()
    print(0)
else:
    print(t)