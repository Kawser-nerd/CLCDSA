# ????
a, b, x = map(int, input().split())

all_count = 0
dev = 0
if b > 0:
    all_count = b // x

if a > 0:
    dev = (a-1) // x
else:
    dev = -1
print(all_count - dev)