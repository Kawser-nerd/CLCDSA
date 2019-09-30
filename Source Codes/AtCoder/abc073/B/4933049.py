N = int(input())
seats = [0 for i in range(100001)]
for i in range(N):
    l, r = map(int, input().split())
    for j in range(l, r+1):
        seats[j] = 1
print(sum(seats))