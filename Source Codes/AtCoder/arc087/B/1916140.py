s = input() + "T"
x, y = map(int, input().split())
N = len(s)



for i in range(N):
    if s[i] == "F":
        x -= 1
    else:
        cnt_Y = True
        index = i + 1
        break

steps_X = []
steps_Y = []

while index < N:
    cnt = 0
    for j in range(index, N):
        if s[j] == "F":
            cnt += 1
        else:
            if cnt_Y and cnt != 0:
                steps_Y.append(cnt)
            elif not cnt_Y and cnt != 0:
                steps_X.append(cnt)
            cnt_Y = not cnt_Y
            index = j
            break
    index += 1
    
K = 10000
dp = [set() for _ in range(K)]
dp[0].add(0)

for i, t in enumerate(steps_X):
    for tmp in dp[i]:
        dp[i+1].add(tmp+t)
        dp[i+1].add(tmp-t)

# print(dp[len(steps_X)])
if x not in dp[len(steps_X)]:
    print("No")
    import sys
    sys.exit()

dp = [set() for _ in range(K)]
dp[0].add(0)
for i, t in enumerate(steps_Y):
    for tmp in dp[i]:
        dp[i+1].add(tmp+t)
        dp[i+1].add(tmp-t)

if y not in dp[len(steps_Y)]:
    print("No")
    import sys
    sys.exit()


print("Yes")