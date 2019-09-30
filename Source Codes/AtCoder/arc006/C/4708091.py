n = int(input().strip())
s = [int(input())]
for _ in range(n-1):
    a = int(input())
    if a > s[-1]:
        s.append(a)
    else:
        for i, j in enumerate(s):
            if j >= a:
                s[i] = a
                break
print(len(s))