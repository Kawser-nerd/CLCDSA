n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

def calc():
    count = 0
    last = 0
    if a[0] > 0:
        return -1
    for v in a:
        if v > last + 1:
            return -1
        if v == last + 1:
            count += 1
        else:
            count += v
        last = v
    return count
print(calc())