n, c = map(int, input().split())
ans = n*c
a = []
num = []
for i in range(n):
    a.append(int(input()))
for i in range(1,11):
    for k in range(1,11):
        ANS = 0
        if i != k:
            for m in range(n):
                if m % 2 == 0:
                    if a[m] != i:
                        ANS += 1
                if m % 2 == 1:
                    if a[m] != k:
                        ANS += 1
            ans = min(ans, ANS)
print(ans*c)