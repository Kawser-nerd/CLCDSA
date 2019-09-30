D, W = map(int,input().split())

dirs = ['N', 'NNE', 'NE', 'ENE', 'E', 'ESE',
        'SE', 'SSE', 'S', 'SSW', 'SW', 'WSW',
        'W', 'WNW', 'NW', 'NNW']
wind = [25, 155, 335, 545, 795, 1075, 1385, 1715,
        2075, 2445, 2845, 3265]

ans1 = dirs[(D * 10 + 1125) // 2250 % 16]
tmp = [x / 100 * 60 for x in wind]
ans2 = len([x for x in tmp if x<=W])

print("C " + str(ans2) if ans2==0 else str(ans1)+" "+str(ans2))