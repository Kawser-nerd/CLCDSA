########????##############
def Base_10_to_n(X, n):
    if (int(X/n)):
        return Base_10_to_n(int(X/n), n)+str(X%n)
    return str(X%n)
############################

def scorecalc(a,target):
    if len(a) == 0:
        ans = 10**9
    else:
        ans = 10*(len(a)-1)
        ans += abs(sum(a)-target)
    return ans

n,a,b,c = map(int,input().split())
l = []
for i in range(n):
    temp = int(input())
    l.append(temp)

mnm = 10**9

for i in range(1,4**n+1):
    test = Base_10_to_n(i,4)
    test = list(test)
    for k in range(n-len(test)):
        test.insert(0,"0")
    fora = []
    forb = []
    forc = []
    for k in range(n):
        if test[k] == "0":
            fora.append(l[k])
        elif test[k] == "1":
            forb.append(l[k])
        elif test[k] == "2":
            forc.append(l[k])
    temp = scorecalc(fora,a) + scorecalc(forb,b) + scorecalc(forc,c)
    if temp < mnm:
        mnm = temp
    
print(mnm)