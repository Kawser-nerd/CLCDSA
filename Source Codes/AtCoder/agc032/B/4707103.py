n = int(input())

ans = []
if n%2 == 0:
    p = [[i, n+1-i] for i in range(1, n//2+1)]
    
    for i in range(len(p)):
        for x in p[i]:
            for j in range(i+1,len(p)):
                for y in p[j]:
                    ans.append([x, y])
else:
    p = [[i, n-i] for i in range(1, (n-1)//2+1)]
    p.append([n])
    
    for i in range(len(p)):
        for x in p[i]:
            for j in range(i+1,len(p)):
                for y in p[j]:
                    ans.append([x, y])
                    
print(len(ans))
for edge in ans:
    print(edge[0], edge[1])