candidate = int(input())
ave_temp, ide_temp = map(float, input().split(' '))
ls_candidate = [abs((ave_temp - (float(x) * 0.006) - ide_temp))  for x in input().split(' ')]

for x, i in enumerate(ls_candidate):
    if ls_candidate[x] == min(ls_candidate):
        print(x + 1)
        break