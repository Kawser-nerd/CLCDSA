A, B, C, D, E, F = map(int, input().split(' '))
water = []
for i in range(31):
    if A*i >= F:
        break
    for j in range(16):
        if 100 * (A*i + B*j) < F:
            water.append(100*(A*i+B*j))
        else:
            break
water = sorted(list(set(water)))

sugar = []
for i in range(max(water)//100*E//C + 1):
    for j in range(max(water)//100*E//D + 1):
        temp_sugar = C*i + D*j
        if temp_sugar + water[1] <= F:
            sugar.append(temp_sugar)
        else:
            break
sugar = sorted(list(set(sugar)))

max_conc = 0
ans_W = 100*A
ans_sugar = 0
for W in water:
    if W == 0:
        continue
    for S in sugar:
        if S+W <= F and S <= W*E//100:
            if max_conc < S/(W+S):
                max_conc = S/(S+W)
                ans_W = W
                ans_sugar = S
        else:
            break
print('{0} {1}'.format(ans_W+ans_sugar, ans_sugar))