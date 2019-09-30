N, a = map(int, input().split())
k = int(input()) 
B = [int(_)-1 for _ in input().split()]
L = [0] * N

a, l = a-1, 0
while k:
    k -= 1
    l += 1
    a = B[a]
    if L[a]:
        k %= l - L[a]
    else:
        L[a] = l
print(a + 1)