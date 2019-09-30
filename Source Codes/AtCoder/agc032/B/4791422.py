N = int(input())
ban = N if N%2 else N+1

ans = []
for i in range(1,N):
    for j in range(i+1,N+1):
        if i+j == ban: continue
        ans.append(str(i) + ' ' + str(j))

print(len(ans))
print(*ans, sep='\n')