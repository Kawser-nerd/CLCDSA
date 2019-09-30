#7
n = int(input())
a = []
b = [0]*n
k = 0
for i in range(n):
    s = input()
    if s not in a:
        a.append(s)
        b[k] +=1
        k += 1
    else:
        b[a.index(s)] += 1
print(a[b.index(max(b))])