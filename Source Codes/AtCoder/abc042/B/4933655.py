# ????
n, l = map(int, input().split())

# ?????
# for i in range(h):
lines = sorted([str(input()) for i in range(n)])

test = ""
for line in lines:
    test += line

print(test)