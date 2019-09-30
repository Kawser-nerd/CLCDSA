a,b = map(int,input().split(" "))
ar = [0 for i in range(a)]
for i in range(b):
    c,d = map(int,input().split(" "))
    ar[c-1] += 1
    ar[d-1] += 1
for r in ar:
    if r % 2 == 1:
        print("NO")
        exit()
print("YES")