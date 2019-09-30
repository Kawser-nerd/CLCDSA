a,b,k,l = map(int,input().split())

ans = 0
ans1 = b*(k//l)+a*(k%l)
ans2 = b*(k//l+1)

print(min(ans1,ans2))