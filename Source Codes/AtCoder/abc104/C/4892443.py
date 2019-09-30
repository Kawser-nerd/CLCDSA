import copy

def calc(wk, kouho, G):
    ans = 0
    for i in range(D):
        if kouho[i] == 1:
            G -= wk[i][1] + 100*(i+1)*wk[i][0]
            ans += wk[i][0]
            wk[i][0] = 0
    if G <= 0:
        return ans
    solve = D-1
    while G > 0 and solve >= 0:
        if wk[solve][0] >= 2: #2????????????
            wk[solve][0] -= 1 #?????1???
            G -= 100*(solve+1) #???????
            ans += 1
        if wk[solve][0] <= 1: #?????or?????????????
            solve -= 1 #????????
    return ans if G <= 0 else 10000

D, G = map(int,input().split())
#100-100*D????????????????
zenbu = 2**D
prob = []
min = 10000
for i in range(D):
    prob.append(list(map(int,input().split())))
for i in range(zenbu):
    work = copy.deepcopy(prob)
    kouho = []
    key = i
    for j in range(D):
        kouho.append(key % 2)
        key //= 2
    res = calc(work, kouho, G)
    if res < min:
        min = res
print(str(min))