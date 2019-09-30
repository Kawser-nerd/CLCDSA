n, arr, dp = int(input()), list(map(int, input().split())), 1
for a in arr:
    dp |= dp << a
ofs = (sum(arr) + 1) // 2
dp >>= ofs
print((dp & -dp).bit_length() + ofs - 1)