n = int(input())
tot = 0

for _ in range(n):
    L = list(input().split())
    if L[1] == "JPY":
        tot += int(L[0])
    else:
        tot += float(L[0])*380000.0

print(tot)