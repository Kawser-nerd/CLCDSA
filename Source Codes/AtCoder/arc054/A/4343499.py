l, x, y, s, d = map(int, input().split())
print(min((d-s)%l/(x+y), (s-d)%l/abs(x-y)) if x<y else (d-s)%l/(x+y))