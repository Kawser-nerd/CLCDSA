#A
"""
n = int(input())
print(2*n)
"""

#B
"""
a1 = list(map(str, input().split()))
a2 = list(map(str, input().split()))
a3 = list(map(str, input().split()))
a4 = list(map(str, input().split()))

ans = []
ans.append(a1)
ans.append(a2)
ans.append(a3)
ans.append(a4)

for i in range(3,-1,-1):
    for k in range(3,-1,-1):
        print(ans[i][k], end=" ")
    print()
"""

#C
"""
n = int(input())
n = n % 30
ans = ["123456"]
for i in range(30):
    ansb = list(ans[i])
    ansb[i % 5] = ans[i][i % 5 + 1]
    ansb[i % 5 + 1] = ans[i][i % 5]
    ansc = ""
    for k in range(6):
        ansc += ansb[k]
    ans.append(ansc)
print(ans[n])
"""

#D
r, g, b = map(int, input().split())

def count(hidari, kosuu):
    if kosuu <= r:
        return abs(400 - hidari)
    elif kosuu <= r + g:
        return abs(500 - hidari)
    else:
        return abs(600 - hidari)
 
#??-500?0???

dp = [[float("INF") for i in range(r+g+b+1)] for _ in range(1002)] 

for i in range(1002):
    dp[i][0] = 0 

for i in range(1, 1002):
    for k in range(1, r + g + b + 1):
        dp[i][k] = min(dp[i - 1][k - 1] + count(i, k), dp[i - 1][k])

print(dp[-1][-1])