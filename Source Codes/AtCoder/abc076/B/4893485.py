N = int(input())
K = int(input())

tmp = 1
for i in range(0,N):
    tmp = min(tmp + K,tmp * 2)

print(tmp)