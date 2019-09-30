pointnum = int(input())

points = []

for i in range(pointnum):
    points.append(i+1)


d_list = []

for i in points:
    if i < len(points):
        print("? {0} {1}".format(points[0], points[i]))
        d_list.append(int(input()))


one_edge = d_list.index(max(d_list)) + 2

e_list = []

points.remove(one_edge)

for i in points:
    print("? {0} {1}".format(one_edge, i))
    e_list.append(int(input()))


print("! {}".format((max(e_list))))