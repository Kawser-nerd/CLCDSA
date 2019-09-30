n = int(input())
k = int(input())

val = 1
for i in range(n):
    if k <= val:
        val = val + k
    else:
        val = val * 2

print(val)