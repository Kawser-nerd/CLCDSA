deg10,dis_m = map(int, input().split())

deg = deg10 / 10
deg_c = 'N'
for i, deg_c_c in enumerate(['N','NNE','NE','ENE','E','ESE','SE','SSE','S','SSW','SW','WSW','W','WNW','NW','NNW']):
    deg_range_min = i * 22.5 - 11.25
    deg_range_max = i * 22.5 + 11.25
    if deg_range_min <= deg and deg < deg_range_max:
        deg_c = deg_c_c
        break

dis_ = dis_m / 6
dis,_n = divmod(dis_, 1)
if _n >=0.5:
    dis = dis+1
dis = dis / 10

if dis <= 0.2:
    w = 0
    deg_c = 'C'
elif dis <= 1.5:
    w = 1
elif dis <= 3.3:
    w = 2
elif dis <= 5.4:
    w = 3
elif dis <= 7.9:
    w = 4
elif dis <= 10.7:
    w = 5
elif dis <= 13.8:
    w = 6
elif dis <= 17.1:
    w = 7
elif dis <= 20.7:
    w = 8
elif dis <= 24.4:
    w = 9
elif dis <= 28.4:
    w = 10
elif dis <= 32.6:
    w = 11
else:
    w = 12

print("{} {}".format(deg_c, w))