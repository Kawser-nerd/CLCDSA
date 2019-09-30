N, S, T = map(int, input().split())
l = [int(input()) for _ in range(N)]
a = 0 
k = l[0]
if l[0] >= S and l[0] <= T:
    a += 1
for i in range(N - 1):
    if k + l[i + 1] >= S and k + l[i + 1] <= T:
        a += 1
    k += l[i + 1]
print(a)