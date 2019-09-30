N = int(input())
A = [int(i) for i in input().split()]
count = [0 for _ in range(N+1)]

if N % 2 == 0:
    if len(set(A)) != int(N/2):
        print(0)
        exit()
else:
    if len(set(A)) != int(N/2)+1:
        print(0)
        exit()

for i in A:
    count[i] += 1

#print(count)

res = 1
for i in range(N+1):
    if count[i] == 2:
        res *= 2
    else:
        if count[i] != 0:
            if N % 2 == 1 and i != 0: 
                print(0)
                exit()

print(res % (10**9+7))