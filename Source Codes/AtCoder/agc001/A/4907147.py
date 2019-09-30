N = int(input())
L = [int(i) for i in input().split()]
L.sort()
L = L[0::2]
print(sum(L))