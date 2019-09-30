#input
n, h = map(int, input().split())
A = []
B = []
for i in range(n):
    a, b = map(int,input().split())
    A.append(a)
    B.append(b)
#manipulation
count = 0
a = max(A)
B.sort(reverse=True)
for b in B:
    if (b > a) & (h > 0):
        h -= b
        count += 1
if h > 0:
    count += (h + a - 1) // a
#output
print(count)