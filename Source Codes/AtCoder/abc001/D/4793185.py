N = int(input())


def delete(list_x):
    list_x = [tuple(i) for i in list_x]
    list_x = [list(i) for i in set(list_x)]
    return list_x


def sort(list_x):
    list_order = []
    dict_x = {}
    for i in list_x:
        dict_x[i[0]] = i
        list_order.append(i[0])

    list_order.sort()

    ct = 0
    for i in list_order:
        list_x[ct] = dict_x[i]
        ct += 1

    return list_x


list_se = []
for i in range(N):
    s, e = map(str, input().strip().split('-'))
    s = [i for i in s]
    e = [i for i in e]
    s_hh, s_h, s_mm, s_m = int(s[0]), int(s[1]), int(s[2]), int(s[3])
    e_hh, e_h, e_mm, e_m = int(e[0]), int(e[1]), int(e[2]), int(e[3])
    if s_m < 5:
        s[3] = '0'
    elif s_m >= 5:
        s[3] = '5'
    if e_m == 0 or e_m == 5:
        pass
    elif e_m < 5:
        e[3] = '5'
    elif e_m > 5:
        e[3] = '0'
        e[2] = str(e_mm+1)
        if e[2] == '6':
            e[2] = '0'
            if e_h < 9:
                e[1] = str(e_h+1)
            else:
                e[1] = '0'
                e[0] = str(int(e[0])+1)
    list_se.append([int(''.join(s)), int(''.join(e))])

list_se = delete(list_se)

list_rain = []
for i in range(2401):
    list_rain.append(0)

for i in list_se:
    s = i[0]
    f = i[1]
    for j in range(s, f+1):
        list_rain[j] = 1

list_time = []
idx = 0
for i in list_rain:
    if idx == 0 and i == 1:
        s = idx
    elif idx > 0 and i == 1 and list_rain[idx-1] == 0:
        s = idx
    if idx == 2400 and i == 1:
        f = idx
        list_time.append([s, f])
    elif idx < 2400 and i == 1 and list_rain[idx+1] == 0:
        f = idx
        list_time.append([s, f])
    idx += 1

list_se = sort(delete(list_se))

for i in list_time:
    i = [str(j).zfill(4) for j in i]
    print('-'.join(i))