N,x = map(int, input().rstrip().split())
a = list(map(int, input().rstrip().split()))
a.sort()
counter = 0
for i,n in enumerate(a):
    x -= n
    if x >= 0 and i != N-1:
        counter += 1
    elif x == 0:
        counter += 1
        break
    else:
        break
print(counter)