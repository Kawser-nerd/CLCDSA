MOD = 10**9+7

a,b = map(int,input().split())
res = 1
for i in range(1,b):
    res = res*(a+b-i-1)*pow(i,MOD-2,MOD)%MOD
print(res)