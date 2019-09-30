N = int(input())
L = []
for i in range(N) :
    l = input()[::-1]
    L.append(l)
L = sorted(L)
for i in range(N) :
    ans = L[i][::-1]
    print(ans)