N = int(input())
h = [[] for i in range(21)]

for i in range(2, N+1):
    b = int(input())
    h[b].append(i)

salary = [0]*(N+1)
for i in range(N, 0, -1):
    if h[i] == []:
        salary[i] = 1
    elif len(h[i])==1:
        salary[i] = salary[h[i][0]]*2 + 1
    else:
        max = 0
        min = float("inf")
        
        for j in range(len(h[i])):
            if max < salary[h[i][j]]:
                max = salary[h[i][j]]
            if min > salary[h[i][j]]:
                min = salary[h[i][j]]
        salary[i] = max + min + 1

print(salary[1])