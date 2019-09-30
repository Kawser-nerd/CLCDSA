n,a,b = (int(i) for i in input().split())
sd = [[i for i in input().split()] for i in range(n)]

res = 0
for s, d in sd:
    dist = min(b,max(a,int(d)))

    if s == "East":
        res += dist
    else:
        res -= dist

if res == 0:
    print(0)
elif res > 0:
    print("East {}".format(res))
else:
    print("West {}".format(-res))