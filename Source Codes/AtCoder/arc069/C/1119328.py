N = int(input())
a = list(map(int, input().split()))
b = [ (a[i], i, 0) for i in range(N)]

b.sort(key= lambda x: (-x[0], x[1]))

# print(b)

mini = 0

for i in range(N-1):
    if b[i][1] < b[mini][1]:
        mini = i

    b[mini] = b[mini][0], b[mini][1], b[mini][2] + (b[i][0]-b[i+1][0])*(i+1)

if b[N-1][1] < b[mini][1]:
    mini = N-1
b[mini] = b[mini][0], b[mini][1], b[mini][2] + (b[N-1][0])*N

b.sort(key = lambda x: x[1])

for x in b:
    print(x[2])