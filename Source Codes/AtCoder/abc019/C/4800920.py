n = int(input())
a = list(map(int, input().split()))
S = set()

for i in range(n):
    while a[i] % 2 == 0:
        a[i] /= 2
    S.add(a[i])
    

print(len(S))