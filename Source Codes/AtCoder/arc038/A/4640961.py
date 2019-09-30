n = int(input())
L = sorted(list(map(int,input().split())),reverse=True)
print(sum(L[::2]))