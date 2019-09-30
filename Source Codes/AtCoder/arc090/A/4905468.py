N = int(input())
A1 = list(map(int, input().split()))
A2 = list(map(int, input().split()))

count1 = [A1[0]] * N
count2 = [A2[-1]] * N
for i in range(1, N):
    count1[i] = count1[i-1] + A1[i]
    count2[N-1-i] = count2[N-i] + A2[N-1-i]

candy = 0
for i in range(0, N):
    candy = max(candy, count1[i] + count2[i])

print(candy)