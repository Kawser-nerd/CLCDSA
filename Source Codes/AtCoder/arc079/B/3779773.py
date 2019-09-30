K=int(input())

i=K//50
j=K%50

ans = []

for k in range(j):
    ans.append(100+i-j)
for k in range(50-j):
    ans.append(50+i-1-j)

print(50)
print(*ans)