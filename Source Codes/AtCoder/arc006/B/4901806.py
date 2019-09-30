N,L = map(int,input().split())
src = [input() for i in range(L)]
end = input()

order = list(range(1,N+1))
for row in src:
    for i in range(1,2*N-1,2):
        if row[i] == ' ': continue
        j,k = (i-1)//2, (i+1)//2
        order[j],order[k] = order[k],order[j]
goal = end.index('o')//2
print(order[goal])