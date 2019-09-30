w,h = map(int,input().split())
ans = 1
mod = 10**9 + 7
for i in range(w-1):
    ans = ans*(i+h)%mod*pow(i+1,mod-2,mod)%mod
print(ans)