n = int(input())
L = list(map(int,input().split()))
print(sum([80 - L[i] for i in range(n) if L[i] < 80 ]))