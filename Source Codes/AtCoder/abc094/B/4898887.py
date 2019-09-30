N, M, X = map(int, input().split())
A = list(map(int, input().split()))

num = 0
for i in A:
    if i<X:
        num += 1
    else: break

print(min(num, M-num))