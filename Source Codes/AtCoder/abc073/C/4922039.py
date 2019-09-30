n = int(input())

bit = {}
for i in range(n):
    a = int(input())
    if a not in bit:
        bit[a] = 1 
    else:
        if bit[a]:
            bit[a] = 0
        else:
            bit[a] = 1
print(sum(bit.values()))