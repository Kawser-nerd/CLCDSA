N,M = map(int,input().split())
ans = 0
ans += min(N,M//2)
ans += (M-min(N,M//2)*2)//4    
print(ans)