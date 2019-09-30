import sys
input = sys.stdin.readline

N = int(input())
train = [[int(_) for _ in input().split()] for _ in range(N-1)]

for i in range(N-1):
    ans = 0
    for j in range(i, N-1):
        if ans <= train[j][1]:
            ans = train[j][1]
        elif ans%train[j][2] != 0:
            ans += train[j][2] - (ans%train[j][2])
        
        ans += train[j][0]
    print(ans)

print(0)