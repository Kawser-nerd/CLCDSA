N = int(input())

d = []
for i in range(N):
    d.append(int(input()))

d.sort()

counter = 1
for i in range(N-1):
    if d[i] - d[i+1] != 0:
        counter += 1
print(counter)