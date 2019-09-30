input_rain_list = []
N = int(input())

for i in range(N):
    input_rain_list.append(list(map(str,input().split('-'))))

for i in range(N):
    for j in range(2):
        fix_value = int(input_rain_list[i][j][-2:]) % 5
        if j == 1 and fix_value != 0:
            fix_value = -(5 - fix_value)
        input_rain_list[i][j] = int(input_rain_list[i][j]) - fix_value
        if str(input_rain_list[i][j])[-2:] == '60':
            input_rain_list[i][j] += 40 
rain_list = sorted(input_rain_list)

i = 0
while i < len(rain_list)-1:
    if rain_list[i][0] <= rain_list[i+1][0] and rain_list[i+1][0] <= rain_list[i][1]:
        if rain_list[i][1] < rain_list[i+1][1]:
            rain_list[i][1] = rain_list[i+1][1]
        rain_list.pop(i+1)
    else:
        i += 1

for rain in rain_list:
    print('{0:04}-{1:04}'.format(rain[0],rain[1]))