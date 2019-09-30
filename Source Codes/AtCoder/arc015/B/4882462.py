d1 = d2 = d3 = d4 = d5 = d6 = 0
for _ in range(int(input())):
    ma,mi = map(float,input().split())

    if ma < 0:d6+= 1
    elif 35 <= ma:d1 += 1
    elif 30 <= ma < 35:d2 += 1
    elif 25 <= ma < 30:d3 += 1

    if 25 <= mi:d4 += 1
    if mi < 0 and 0 <= ma:d5 += 1
    #if ma < 0:d6 += 1
print(d1,d2,d3,d4,d5,d6)