N = int(input())
dp = [0 for i in range(N+1)]
dp[1] = 1
kazu = [1]
i = 6
while i <= N:
    kazu.append(i)
    i*=6
i = 9
while i <= N:
    kazu.append(i)
    i*=9
kazu.sort()
kazulazor = len(kazu)
temp = [1]
lentemp = 1
index = 1
for i in range(2, N+1):
    kouho = []
    if index < kazulazor and i == kazu[index]:
        temp.append(i)
        index += 1
        lentemp += 1
    for j in range(lentemp):
        kouho.append(dp[i-temp[j]]+1)
    dp[i] = min(kouho)
print(str(dp[N]))