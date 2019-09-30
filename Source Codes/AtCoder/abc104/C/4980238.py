d, g = map(int, input().split())
comp_points = []
P = []
for i in range(d):
    p, c = map(int, input().split())
    comp_points.append([p, (i + 1) * 100 * p + c])
    P.append(p)

ans = 10**10
#bitallsearch
for i in range(2 ** d):
    bit = format(i, "b").zfill(d)
    count = 0
    point = 0
    for j, dot in enumerate(bit):
        if dot == "1":
            count += comp_points[j][0]
            point += comp_points[j][1]
    #add shortage form high point not comp_points
    for b in range(d-1, -1, -1):
        flag = False
        if point >= g:
            ans = min(ans, count)
            break
        if bit[b] == "0":
            flag = True
            for p in range(P[b] - 1):
                count += 1
                point += (b+1) * 100
                if point >= g:
                    ans = min(ans, count)
                    break
        if (point < g) & flag:
            break

print(ans)