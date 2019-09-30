N = int(input())
A = [int(a) for a in input().split()]

pre = -1
c = 0
ans = 0
for a in A:
    if a == pre:
        c += 1
        if c % 2 == 0:
            ans += 1
    else:
        c = 1
    pre = a
    
print(ans)