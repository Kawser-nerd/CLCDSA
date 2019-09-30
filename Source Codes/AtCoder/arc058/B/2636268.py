H, W, A, B = map(int, input().split())
mod = 10**9+7

count = 0

factoriallist = [1]*(H+W)
for i in range(1,H+W):
    factoriallist[i] = factoriallist[i-1]*i % mod
#print("fact",factoriallist)

inverse_factoriallist = [0]*(H+W)
inverse_factoriallist[H+W-1] = pow(factoriallist[H+W-1],mod-2,mod)
#print("inverse",inverse_factoriallist)
for i in range(H+W-2,-1,-1):
    
    inverse_factoriallist[i] = inverse_factoriallist[i+1] * (i+1) % mod
    #print("inverse",inverse_factoriallist)


for i in range(B, W):
    count += ((factoriallist[H-A+i-1] * inverse_factoriallist[H-A-1] * inverse_factoriallist[i] )%mod) * ((factoriallist[A+(W-i) -2] * inverse_factoriallist[A-1] * inverse_factoriallist[W-i-1])%mod)

print(int(count% mod))