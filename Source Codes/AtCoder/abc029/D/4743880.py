N=[int(x) for x in list(input())]
digit=len(N)
DP=[[[0]*(digit+1) for _ in range(2)] for _ in range(digit+1)]
DP[0][0][0]=1
for d in range(digit):
    for less in range(2):
        for num in range(digit):
            limit=9 if less else N[d]
            for l in range(limit+1):
                DP[d+1][less or l<limit][num+(l==1)]+=DP[d][less][num]
ans=0
for less in range(2):
    for num in range(digit+1):
        ans+=DP[digit][less][num]*num
print(ans)