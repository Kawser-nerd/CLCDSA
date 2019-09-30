def b_days(N, Observations):
    day_mousho, day_manatsu, day_natsu, day_nettai, day_fuyu, day_mafuyu = 0, 0, 0, 0, 0, 0
    for highest_temp, lowest_temp in Observations:
        if '.' in highest_temp:
            highest_temp = int(highest_temp.replace('.', ''))
        else:
            highest_temp = int(highest_temp) * 10

        if '.' in lowest_temp:
            lowest_temp = int(lowest_temp.replace('.', ''))
        else:
            lowest_temp = int(lowest_temp) * 10

        if highest_temp >= 350:
            day_mousho += 1
        elif 300 <= highest_temp < 350:
            day_manatsu += 1
        elif 250 <= highest_temp < 300:
            day_natsu += 1

        if lowest_temp >= 250:
            day_nettai += 1

        if lowest_temp < 0 and highest_temp >= 0:
            day_fuyu += 1

        if highest_temp < 0:
            day_mafuyu += 1

    ans = ' '.join(map(str, [day_mousho, day_manatsu, day_natsu, day_nettai, day_fuyu, day_mafuyu]))

    return ans

N = int(input())
Observations = [[i for i in input().split()] for j in range(N)]
print(b_days(N, Observations))