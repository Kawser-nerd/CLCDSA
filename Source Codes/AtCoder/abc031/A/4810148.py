a, d = map(int, input().split())

if a > d:
    a, d = d, a
    
print((a+1) * d)