n = int(input())
ans = 0
for i in range(n):
    a,b = map(int,input().split())
    ans += a*b
print(int((ans*1.05 // 1)))