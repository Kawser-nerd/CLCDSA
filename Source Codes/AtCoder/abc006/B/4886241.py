N = int(input())
trib = [0, 0, 1]
for i in range(3, N):
    trib.append((trib[i - 1] + trib[i - 2] + trib[i - 3]) % 10007)
print(trib[N-1])