n = int(input())

if n == 1:
    print(1)
    exit()

b = [-1] + [int(input()) - 1 for _ in range(n-1)]

a = [[] for _ in range(n)]

for i in range(1, n):
    a[b[i]].append(i)

def pay(x):
    if len(a[x]) == 0:
        return 1
    else:
        temp = set()
        for t in a[x]:
            temp.add(pay(t))
        return max(temp) + min(temp) + 1

print(pay(0))