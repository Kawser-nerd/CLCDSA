N = int(input())
X = list(map(int, input().split()))
s = sorted(X)
a = s[N // 2 - 1]
b = s[N // 2]

for x in X:
    if x <= a:
        print(b)
    else:
        print(a)