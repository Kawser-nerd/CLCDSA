h, m = map(int, input().split())

ans = 0
if m != 0:
    ans += 60 - m
    ans += (18 - h - 1) * 60
else:
    ans += (18 - h) * 60
    
print(ans)