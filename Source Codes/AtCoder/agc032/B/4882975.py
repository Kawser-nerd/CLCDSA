n = int(input())
ans = []
taboo = n if n%2 else n+1
for i in range(1,n):
    for j in range(i+1,n+1):
        if i+j == taboo: continue
        ans.append(str(i) + ' ' + str(j))
print(len(ans))
print(*ans,sep='\n')