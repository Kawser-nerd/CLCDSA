a = int(input())
count = 0
ar = []
for i in range(a):
    l = int(input())
    count += l
    if l % 10 != 0:
        ar.append(l)
if count % 10 != 0:
    print(count)
else:
    if len(ar) == 0:
        print(0)
    else:
        print(count - min(ar))