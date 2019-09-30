N, Q = map(int, input().split())

COUNT = [0] * (N+1)

for _ in range(Q):
    l, r = map(int, input().split())
    COUNT[l-1] += 1
    COUNT[r] -= 1




for i in range(N):
    COUNT[i+1] = COUNT[i]  + COUNT[i+1]

for i in range(N):    
    #COUNT[i] = (COUNT[i] % 2)
    COUNT[i] %= 2

print("".join(map(str, COUNT[0:N])))