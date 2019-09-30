N = int(input())
A = [0]*N
B = [0]*N
hoge = int(1e18)
for i in range(N):
    a, b = map(int, input().split())
    A[i] = a
    B[i] = b
    if a > b:
        hoge = min(hoge, b)

if hoge == int(1e18):
    print(0)
else:
    print(sum(B) - hoge)