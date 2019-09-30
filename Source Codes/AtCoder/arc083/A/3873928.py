A, B, C, D, E, F = map(int, input().split(' '))

max_sugar = 0
max_water = 100*A
max_conc = 0.0
A_limit = F // (100*A)
for i in range(A_limit + 1):
    B_limit = (F-100*A*i) // (100*B)
    for j in range(B_limit + 1):
        if i == 0 and j == 0:
            continue
        sugar_limit = min(E * (A*i+B*j), F-100*(A*i+B*j))

        sugar_ = 0
        for c in range(sugar_limit//C + 1):
            d = (sugar_limit-c*C)//D
            temp_sugar = c*C + d*D
            sugar_ = max(sugar_, temp_sugar)
        temp_conc = sugar_/(sugar_+100*(A*i+B*j))
        if temp_conc > max_conc:
            max_conc = temp_conc
            max_water = 100*(A*i + B*j)
            max_sugar = sugar_
print('{0} {1}'.format(max_water+max_sugar, max_sugar))