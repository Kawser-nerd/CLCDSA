#!/mnt/c/Users/moiki/bash/env/bin/python
N = int(input())
in_red = [tuple(map(int, input().split())) for _ in range(N)]
in_blu = [tuple(map(int, input().split())) for _ in range(N)]
in_red = sorted(in_red, key=lambda x: x[1], reverse=True)
in_blu = sorted(in_blu)

# print(in_red)
# print(in_blu)

ans = 0
for ei,x in enumerate(in_blu):
    x,y = x
    # print("x: {}, x,y: {}, {}".format(x,x,y))

    idx = 0
    found = False
    for e,p in enumerate(in_red):
        # print("\tp: {}, {}".format(p[0], p[1]))
        if p[0] < x and p[1] < y:
            idx = e
            found = True
            break
    if found:
        ans += 1
        in_red.pop(idx)
print(ans)