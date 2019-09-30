n = int(input())
mt, ma = 1, 1
for t, a in (map(int, input().split()) for _ in range(n)):
    l = max((mt-1)//t, (ma-1)//a)  + 1
    mt, ma = l*t, l*a
print(mt+ma)
#copy code