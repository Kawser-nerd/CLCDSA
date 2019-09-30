N = int(input())
a = list(map(int, input().split()))
min_num = min(a)
max_num = min_num*2 if a.count(min_num) == 1 else min_num*2-1
o, x = "Possible", "Impossible"

if max(a) != max_num:
    print(x)
elif not 1 <= a.count(min_num) <= 2:
    print(x)
else:
    for n in range(min_num+1, max_num+1):
        if a.count(n) < 2:
            print(x)
            break
    else:
        print(o)