N = int(input())
c=list(map(int, input().split()))
c.sort()
Max = 0
for i in range(len(c)):
    if i%2 == 0:
        Max = Max + c[i]
    else:
        None
print(Max)